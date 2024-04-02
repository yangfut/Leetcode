class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // 1. double-ended queue
        deque<int>deq(arr.begin(), arr.end());
        int maxv=arr[0];
        for(int ele:arr) maxv=max(maxv,ele);
        if(k>arr.size()) return maxv;
        int win_count=0;
        while(win_count<k){
            int a=deq.front(); deq.pop_front();
            int b=deq.front(); deq.pop_front();

            if(a>b){
                deq.push_front(a);
                deq.push_back(b);
                ++win_count;
            }else{
                deq.push_front(b);
                deq.push_back(a);
                win_count=1;
            }
        }
        return deq.front();


    }
};