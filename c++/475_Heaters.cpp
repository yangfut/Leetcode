class Solution {
public:
    int binary_search(vector<int>&heaters, int val){
        //lower bound binary search
        int low=0;
        int high=heaters.size();

        while(low<high){
            int mid=low+(high-low)/2;
            if(heaters[mid]<val) low=mid+1;
            else high=mid;
        }
        return low;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //Use binary search for a house to find out nearest heater from its left side and right side
        //nearest heater(temp_radius) by getting minimum value between leftDist and rightDist
        //Update radius by getting maximum value between radius and temp_radius
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for(int i=0;i<houses.size();++i){
            int pos = binary_search(heaters, houses[i]);
            // cout << pos << endl;

            int leftDist = (pos > 0) ? houses[i] - heaters[pos-1] : INT_MAX;
            int rightDist = (pos < heaters.size()) ? heaters[pos] - houses[i] : INT_MAX;
            int temp_radius = min(leftDist, rightDist);
            // cout << leftDist << ":" <<rightDist << ":" << temp_radius <<endl;
            radius = max(temp_radius, radius);
        }
        return radius;
    }
};