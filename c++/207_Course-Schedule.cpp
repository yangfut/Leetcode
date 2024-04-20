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