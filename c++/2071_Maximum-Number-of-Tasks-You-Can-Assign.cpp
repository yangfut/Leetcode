class Solution {
    bool helper(vector<int>& tasks, vector<int>& workers, int p, int str, int mm){
        multiset<int> st_workers(workers.begin(), workers.end());
        for(int i = mm; i >= 0; --i){
            
            int t = tasks[i];
            // since the required task can't be completed, use the pill to decrease the tasks[i]
            // Not just take the max power worker, but take the proper workder for this case by doing binary search
            if(t > *st_workers.rbegin() && p > 0){
                t -= str;
                --p;
            }

            auto x = st_workers.lower_bound(t);
            if(x == st_workers.end()) return false;
            st_workers.erase(x);
        }

        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // 1. Check if k tasks can be completed
        // 2. If true, check the right bound(k+1, n) of tasks
        // 3. If false, check the left bound(0, k) of tasks

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int ll = 0, hh = min(tasks.size(), workers.size())-1;
        while(ll <= hh){
            int mm = ll + (hh-ll)/2;
            if(helper(tasks, workers, pills, strength, mm)){
                ll = mm+1;
            }else{
                hh = mm-1;
            }
        }
        return hh+1;
    }
};