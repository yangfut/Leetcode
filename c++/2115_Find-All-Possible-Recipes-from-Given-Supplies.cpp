class Solution {
private:
    int dfsHelper(vector<string>& recipes, vector<vector<int>>& adjList, int idx, vector<string>& comb, vector<int>& status){
        
        if(status[idx] == 1) return 0;
        if(status[idx] == -1) return -1; // Cycle detected

        status[idx] = -1; // Mark as visiting

        for(int neighbor: adjList[idx]){
            if(dfsHelper(recipes, adjList, neighbor, comb, status) == -1) return -1;
        }

        status[idx] = 1; // Mask as visited
        comb.push_back(recipes[idx]);
        return 0;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> recToIdx;
        for(int i = 0; i < recipes.size(); ++i){
            recToIdx[recipes[i]] = i;
        }

        unordered_set<string> available_supplies;
        for(string& s : supplies) available_supplies.insert(s);

        int n = recipes.size();
        vector<vector<int>> adjList(n);
        vector<string> comb;
        vector<int> status(n,0); // -1: visiting, 0: not visited, 1: visited 

        for(int i = 0; i < recipes.size(); ++i){
            for(const string& ingredient : ingredients[i]){
                if(available_supplies.count(ingredient)) continue;
                if(recToIdx.count(ingredient)){
                    adjList[i].push_back(recToIdx[ingredient]);
                }else{
                    status[i] = -1; // unknown ingredient
                }
            }
        }

        for(int i = 0; i < recipes.size(); ++i){
            dfsHelper(recipes, adjList, i, comb, status);
        }
        return comb;
    }
};