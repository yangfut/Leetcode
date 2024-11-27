class FoodRatings {
private:
    struct cmp{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            return (a.first == b.first) ? b.second < a.second : a.first < b.first;
        }
    };
    vector<pair<string,int>> m_foods;
    vector<int> m_ratings;
    vector<string> m_cuisines;
    unordered_map<string, int> m_foods_idx;
    unordered_map<string, priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>> m_cuisine_rate;

    bool is_valid_rating(const pair<int, int>& p){
        int idx = m_foods[p.second].second;
        return p.first == m_ratings[idx];
    }
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i){
            m_foods.push_back(make_pair(foods[i], i));
        }
        sort(m_foods.begin(), m_foods.end());

        m_ratings = ratings;
        m_cuisines = cuisines;

        for(int i = 0; i < n; ++i){
            const pair<string, int> &p = m_foods[i];
            int idx = p.second;
            const string &_cu = m_cuisines[idx];

            m_foods_idx[p.first] = i;
            priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> &pq = m_cuisine_rate[_cu];
            pq.push(make_pair(m_ratings[idx], i));
        }
    }
    
    void changeRating(string food, int newRating) {
        
        // find index in m_foods
        int i = m_foods_idx[food];
        const pair<string, int> &p = m_foods[i];

        // update m_ratings
        m_ratings[p.second] = newRating;

        // update m_cuisine_rate
        string &_cu = m_cuisines[p.second];
        m_cuisine_rate[_cu].push(make_pair(newRating, i));
    }
    
    string highestRated(string cuisine) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> &pq = m_cuisine_rate[cuisine];

        while(!is_valid_rating(pq.top())) pq.pop();

        int idx = pq.top().second;
        return m_foods[idx].first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */