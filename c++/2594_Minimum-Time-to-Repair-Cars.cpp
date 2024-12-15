class Solution {
    struct cmp{
        bool operator()(const pair<long long,int>&a, const pair<long long,int>&b){
            long long res_a = a.first*a.first*a.second;
            long long res_b = b.first*b.first*b.second;
            return (res_a == res_b) ? a.second > b.second : res_a > res_b;
        }
    };
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, cmp> minheap;
        for(int r : ranks){
            minheap.push({1, r});
        }

        for(int i = 0; i < cars; ++i){
            pair<long long,int> p = minheap.top();
            p.first++;
            minheap.pop();
            minheap.push(p);
        }
        
        long long times = 0;
        while(!minheap.empty()){
            pair<long long,int> p = minheap.top();
            times = max((p.first-1)*(p.first-1)*p.second, times);
            minheap.pop();
        }
        return times;
    }
};

class Solution {
public:
    bool isPossible(long long time, int cars, const vector<int>&ranks){
        int idx = 0;
        while(cars > 0 && idx < ranks.size()){
            int repaired = sqrt(time /ranks[idx]);
            cars -= repaired;
            ++idx;
        }
        return cars > 0 ? false : true;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long ll = 1, rr = 100 * static_cast<long long>(cars) * static_cast<long long>(cars);
        long long res = 1;
        while(ll <= rr){
            long long mid = ll + (rr-ll)/2;
            if(isPossible(mid, cars, ranks)){
                res = mid;
                rr = mid-1;
            }else{
                ll = mid+1;
            }
        }
        return res;
    }
};