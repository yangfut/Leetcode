class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, area=0;
        while(l<r){
            int temp_area = (r-l) * min(height[l], height[r]);
            if(temp_area>area) area = temp_area;
            if(height[l]>height[r]) --r;
            else ++l;
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int currArea = 0, res = 0;

        while(left < right){
          
          currArea = min(height[left], height[right]) * (right - left);
          res = max(res, currArea);

          if(height[left] <= height[right]){
            ++left;
          }else{
            --right;
          }
        }

        return res;
    }
};