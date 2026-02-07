// Queue with pair of vector pointer and idx
class ZigzagIterator {
public:
    queue<pair<vector<int>*, int>> que;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) que.push({&v1,0});
        if(!v2.empty()) que.push({&v2,0});
    }

    int next() {
        auto [vecPtr, idx]  = que.front();
        que.pop();
        int val = (*vecPtr)[idx];

        // Only push back if there's more data
        if(idx + 1 < vecPtr->size()) que.push({vecPtr, idx+1});
        return val;
    }

    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

// Queue with elements
class ZigzagIterator {
public:
    queue<int> que;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int idxV1 = 0, idxV2 = 0;
        while(idxV1 < v1.size() || idxV2 < v2.size()){
            if(idxV1 < v1.size()) que.push(v1[idxV1++]);
            if(idxV2 < v2.size()) que.push(v2[idxV2++]);
        }
    }

    int next() {
        int res = que.front();
        que.pop();
        return res;
    }

    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */