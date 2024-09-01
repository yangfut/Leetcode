class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> points;
        pair<int, int> curr;
        points.insert(curr);

        for(const char &c : path){
            
            switch(c){
                case 'N':
                    curr.second += 1;
                    break;
                case 'E':
                    curr.first += 1;
                    break;
                case 'S':
                    curr.second -= 1;
                    break;
                case 'W':
                    curr.first -= 1;
                    break;
                default:
                    return false;
                    break;
            }
            
            if(points.count(curr)) return true;
            points.insert(curr);
        }
        return false;
    }
};