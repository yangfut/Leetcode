class Solution {
public:
    void dfsHelper(vector<int>& commands, set<pair<int,int>>& obstacles_set, int idx, pair<int,int>location, int flow, int& maxDist){
      
      // base case
      if(idx == commands.size()) return;

      // Moving foward
      if(commands[idx] > 0){
        int steps = commands[idx];
        int ori_x = location.first;
        int ori_y = location.second;

        int move_x = 0;
        int move_y = 0;
        switch(flow){
          case 0:
            move_y = 1;
            break;
          case 1:
            move_x = 1;
            break;
          case 2:
            move_y = -1;
            break;
          case 3:
            move_x = -1;
            break;
        }

        while(steps != 0){
          if(obstacles_set.count(make_pair(ori_x+move_x, ori_y+move_y))) break;
          ori_x += move_x;
          ori_y += move_y;
          --steps;
        }

        maxDist = max(maxDist, ori_x*ori_x + ori_y * ori_y);
        dfsHelper(commands, obstacles_set, idx+1, make_pair(ori_x, ori_y), flow, maxDist);
        return;
      }


      // Toward right
      if(commands[idx] == -1){
        int newflow = (flow == 3) ? 0 : flow+1;
        dfsHelper(commands, obstacles_set, idx+1, location, newflow, maxDist);
        return;
      }

      // Toward left
      if(commands[idx] == -2){
        int newflow = (flow == 0) ? 3 : flow-1;
        dfsHelper(commands, obstacles_set, idx+1, location, newflow, maxDist);
        return;
      }

    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int,int> location;
        //0: North
        //1: East
        //2: South
        //3: West
        int flow = 0;
        int maxDist = -1;
        set<pair<int,int>> obstacles_set;
        for(auto& p : obstacles){
          obstacles_set.insert(make_pair(p[0], p[1]));
        }
        dfsHelper(commands, obstacles_set, 0, location, flow, maxDist);
        return maxDist;
        
    }
};