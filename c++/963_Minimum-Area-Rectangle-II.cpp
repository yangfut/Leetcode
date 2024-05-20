class Solution {
private:
    long dist(int x1, int y1, int x2, int y2){
        return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        // 1. All four points share the samle middle point
        map<pair<double,double>, vector<pair<int,int>>> centerToPoints;
        long minArea = LONG_MAX;
        int n = points.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                double m_x = static_cast<double>(points[i][0] + points[j][0]) / 2;
                double m_y = static_cast<double>(points[i][1] + points[j][1]) / 2;

                centerToPoints[make_pair(m_x, m_y)].push_back(make_pair(i,j));
            }
        }

        for(const auto& [_, p] : centerToPoints){
            if(p.size() == 1) continue;
            for(const auto& [i, j] : p){
                for(const auto& [k, l] : p){
                    if(i == k) continue;
                    // ik is perpendicular to il
                    // ik dot il should be zero
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[k][0], y2 = points[k][1];
                    int x3 = points[l][0], y3 = points[l][1];

                    if( (x3 - x1) * (x2 - x1) + (y3 - y1) * (y2 - y1) == 0){
                        long d1 = dist(x3,y3,x1,y1);
                        long d2 = dist(x2,y2,x1,y1);
                        minArea = min(minArea, d1*d2);
                    }
                }
            }
        }
        return minArea == LONG_MAX ? 0 : sqrt(minArea);

    }
};