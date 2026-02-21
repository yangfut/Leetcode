// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/
// Two pointers
class SparseVector {
public:
    vector<pair<int,int>> svec;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]){
                svec.emplace_back(i, nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto& vec1 = svec;
        auto& vec2 = vec.svec;
        int idx1 = 0, idx2 = 0, sum = 0;

        while(idx1 < vec1.size() && idx2 < vec2.size()){

            auto& p1 = vec1[idx1];
            auto& p2 = vec2[idx2];

            if(p1.first == p2.first){
                sum += p1.second * p2.second;
                ++idx1;
                ++idx2;
            }else if(p1.first > p2.first) ++idx2;
            else ++idx1;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

// Hash Map
class SparseVector {
public:
    
    unordered_map<int,int> indexValueMap;

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) continue;

            indexValueMap[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map<int,int> &vec1Map = indexValueMap;
        unordered_map<int,int> &vec2Map = vec.indexValueMap;

        int sum = 0;
        for(auto& p : vec1Map){
            if(vec2Map.count(p.first)) sum += (p.second * vec2Map[p.first]);
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);