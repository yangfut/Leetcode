class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // edge case: size can't divide by groupSize
        int n = hand.size();
        if(n % groupSize) return false;

        // create multiset
        multiset<int> st;

        for(int& card : hand) st.insert(card);

        int segmentSize = n / groupSize;
        for(int segment = 0; segment < segmentSize; ++segment){
            // edge case: hand.size() is less than segmentSize * groupSize
            if(st.empty()) return false;

            // find the minimum value among consecutive numbers
            int minv = *st.begin();
            while(st.count(minv-1)) --minv;

            for(int amount = 0; amount < groupSize; ++amount){
                // edge case: unfound expected consecutive number in hand
                if(!st.count(minv)) return false;

                st.erase(st.find(minv));
                ++minv;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // edge case: card can't distribute into groupSize evenly
        int n = hand.size();
        if(n % groupSize) return false;

        // use hash table to collect card value and it's count
        unordered_map<int,int> collection;
        for(int& card : hand) ++collection[card];

        // use min heap to store the minimum value in this collection
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // put all the keys into heap
        for(auto& it : collection) minHeap.push(it.first);

        // iterate if heap is not empty()
        while(!minHeap.empty()){
            // get minimum value by minHeap.top()
            // iterate groupSize to find consecutive numbers in hash table
            // decrement 1 if it's found, and return false if it is not found
            int minv = minHeap.top();
            for(int amount = 0; amount < groupSize; ++amount){

                // edge case: consecutive card doesn't exist
                if(!collection.count(minv)) return false;

                --collection[minv];
                
                // optimized: if some card is out, but it is not the minimum value
                // This implies other segment doesn't have enough card to group
                
                if(collection[minv] == 0){
                    if(minv != minHeap.top()) return false;
                    minHeap.pop();
                } 
                ++minv;
            }

        }
        return true;        
    }
};