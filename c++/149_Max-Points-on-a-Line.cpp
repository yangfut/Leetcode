class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //Base case
        if(points.size()<=2) return points.size();

        //If two points share the same slope(yi-yj/xi-xj), they are in the same line
        int max_count=0;
        for(int i=0;i<points.size();i++){
            unordered_map<float, int>slopeCount;
            for(int j=i+1;j<points.size();j++){
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                float m=(0==dx)?FLT_MAX:(float)dy/dx;
                slopeCount[m]++;
                max_count=max(max_count, slopeCount[m]);
            }
        }

        return max_count+1;

    }
};