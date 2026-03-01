class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        // for(auto& vec : clips) cout << vec[0] << " " << vec[1] << endl;
        int maxEdTime = 0, ed = 0, count = 0;
        for(int i = 0; i < clips.size(); ++i){
            int currSt = clips[i][0];
            int currEd = clips[i][1];
            if(maxEdTime < currSt){
                if(ed < currSt) return -1;
                maxEdTime = ed;
                ++count;
            }

            ed = max(currEd, ed);
            if(maxEdTime >= time) return count;
            if(ed >= time) return count + 1;
        }
        return -1;
    }
};