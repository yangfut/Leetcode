class Solution {
public:
    void dfsCheckPrerequisite(unordered_map<int,vector<int>>& prerequisiteMap, int course, vector<int>& prereq, vector<int>& cache, bool& result){

        cache[course] = 0; // Temporarily set to false
        for(int c : prereq){
            if(cache[c]==-1){
                if(prerequisiteMap.count(c)) dfsCheckPrerequisite(prerequisiteMap, c, prerequisiteMap[c], cache, result);
                else cache[c] = 1;
            }

            if(cache[c]==0){
                result = false;
                return;
            }
        }
        cache[course] = 1; // all its prerequisites are achievable
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Approach: Considering Contradiction(cycle) and Out of bound
        
        // Edge case: no prerequisites
        if(prerequisites.size() == 0) return true;

        unordered_map<int,vector<int>> prerequisiteMap;
        for(auto& course : prerequisites){
            if(course[1] >= numCourses) return false; // Edgecase: prerequisite is out of bound

            if(prerequisiteMap.count(course[0])){
                prerequisiteMap[course[0]].push_back(course[1]);
            }else{
                prerequisiteMap[course[0]] = vector<int>{course[1]};
            }
        }

        // DFS with cache
        bool result = true;
        vector<int> cache(numCourses, -1);
        for(auto& prerequisite : prerequisiteMap){

            // Ensure each prerequisit visited once
            if(cache[prerequisite.first] == -1){
                dfsCheckPrerequisite(prerequisiteMap, prerequisite.first, prerequisite.second, cache, result);
            } 
            if(!cache[prerequisite.first]) break; // Break if result if false
        }

        return result;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, stack<int>& stack, int course){
        
        // Mark the current course as locally visited
        visited[course] = 0;
        for(int neighbor : graph[course]){
            if(visited[neighbor] == -1){
                dfs(graph, visited, stack, neighbor);
            }

            // Return if a cycle is found(No push, so stack size is smaller than numOfCourse)
            if(visited[neighbor] == 0){
                visited[course] = 1;
                return;
            }
        }

        // Mark the current course as globally visited
        visited[course] = 1;

        // Push the current course into stack if all prerequoisites are visited
        stack.push(course);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Create graph
        vector<vector<int>> graph(numCourses);
        for(auto& edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform DFS traversal to determine the topological order
        stack<int> stack;
        vector<int> visited(numCourses, -1);
        for(int course = 0; course < numCourses; ++course){
            if(visited[course] == -1){
                dfs(graph, visited, stack, course);
            }
        }

        // If there is a cycle in graph, stack size must be smaller than numOfCourse
        if(stack.size() < numCourses) return false;
        return true;
    }
};

// DFS-based topological sort

class Solution {
public:
    int dfs(int idx, unordered_map<int, vector<int>>& dep, vector<int>& istaken){
        if(istaken[idx] == 0 || istaken[idx] == 1) return istaken[idx];

        // Mark as visiting
        istaken[idx] = 0;
        if(dep.count(idx)){
            vector<int>& next = dep[idx];
            for(int nextIdx : next) {
                if(dfs(nextIdx, dep, istaken) == 0) return istaken[idx];
            }
        }
        
        return istaken[idx] = 1;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        // Traverse every nodes by dfs()
        // -1: untaken, 0: taking, 1: taken
        vector<int> istaken(n,-1);
        unordered_map<int, vector<int>> dep;
        for(auto& p : preq) dep[p[0]].push_back(p[1]);
        for(int i = 0; i < n; ++i) if(dfs(i, dep, istaken) == 0) return false;
        return true;
    }
};

// BFS-based topological sort aka Kahn's algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto& p : preq){
            // according to "take course bi first if you want to take course ai"
            // bi is root and ai is leaf
            adj[p[1]].push_back(p[0]);
            ++inDegree[p[0]];
        }

        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; ++i) if(inDegree[i] == 0) q.push(i);
        while(!q.empty()){
            int curr = q.front(); 
            q.pop();
            ++count;
            for(int i : adj[curr]) {
                --inDegree[i];
                if(inDegree[i] == 0) q.push(i);
            }
        }
        return count == n;
    }
};

// Iterative DFS-based topological sort
class Solution {
public:
    bool dfs(int idx, vector<int>& istaken, vector<vector<int>>& dep){
        stack<pair<int,int>> stk;
        stk.push({idx, 0});
        istaken[idx] = 0;

        while(!stk.empty()){
            auto& [i, childIdx] = stk.top();

            // boundary check
            if(childIdx == dep[i].size()){
                istaken[i] = 1;
                stk.pop();
                continue;
            }


            int nxt = dep[i][childIdx++];
            if(istaken[nxt] == 1) continue;
            if(istaken[nxt] == 0) return false;

            istaken[nxt] = 0;
            stk.push({nxt, 0});
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> dep(n);
        vector<int> istaken(n, -1);
        for(auto& p : preq) dep[p[0]].push_back(p[1]);
        for(int i = 0; i < n; ++i){
            if(istaken[i] == -1 && !dfs(i, istaken, dep)) return false;
        }
        return true;
    }
};