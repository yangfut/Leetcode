class DetectSquares {
public:
    // count duplicated points
    map<pair<int,int>, int> point_count;
    
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        pair<int,int> p = {point[0], point[1]};
        ++point_count[p];
    }
    
    int count(vector<int> point) {
        
        int x1 = point[0], y1 = point[1];
        int square_count = 0;

        //detect square
        for(auto it = point_count.begin(); it != point_count.end(); ++it){

            int x2 = it->first.first;
            int y2 = it->first.second;

            if(x1 == x2 || y1 == y2) continue;
            if(point_count.count(make_pair(x1,y2)) && point_count.count(make_pair(x2,y1)) && abs(x2-x1) == abs(y2-y1)){
                square_count += point_count[make_pair(x1,y2)] * point_count[make_pair(x2,y1)] * it->second;
            }
        }
        return square_count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */