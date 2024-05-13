#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // sort the meetings by start
        sort(meetings.begin(), meetings.end());

        priority_queue<pair<unsigned long,int>, vector<pair<unsigned long,int>>, greater<pair<unsigned long,int>>> occupied;
        priority_queue<int,vector<int>, greater<int>> available;
        vector<int> used_count(n);
        int most_used_room = 0, max_count = 0;
        
        // initialize all available rooms
        for(int room = 0; room < n; ++room) available.push(room);

        // iterate through meetings
        for(unsigned long time = 0, idx = 0; idx < meetings.size(); ++idx){
            
            // update current time if needed
            if(time < static_cast<unsigned long>(meetings[idx][0])) time = static_cast<unsigned long>(meetings[idx][0]);

            // adjust time if no available room
            if(available.empty()) time = max(time, occupied.top().first);

            // release occupied rooms
            while(!occupied.empty() && time >= occupied.top().first){
                available.push(occupied.top().second);
                occupied.pop();
            }

            // book meeting room
            int this_room = available.top();
            ++used_count[this_room];
            int count = used_count[this_room];

            if(count > max_count){
                max_count = count;
                most_used_room = this_room;
            }else if(count == max_count) most_used_room = min(most_used_room, this_room);

            // update occupied and available rooms
            unsigned long duration = meetings[idx][1] - meetings[idx][0];
            occupied.push(make_pair(time + duration, this_room));
            available.pop();
        }

        return most_used_room;
    }
};