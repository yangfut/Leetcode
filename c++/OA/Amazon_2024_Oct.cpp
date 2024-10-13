/*
In managing tasks at analytics platform, the goal is to efficiently schedule both primary and secondary tasks within specified time constraints.
There are n primary tasks and n secondary tasks. Two arrays, primary and secondary, provide information on task hours, where primary[i] represents the duration in hours of the ith primary task, and secondary[i] represents the duration in hours of the ith secondary task.
Each day on the platform has a time limit denoted as limit hours. One primary task must be scheduled each day. If time remains after the primary task, you can choose to schedule at most one secondary task on that day. It's essential to ensure that the total hours does not exceed the specified limit hours.
Determine the maximum number of secondary tasks that can be scheduled during these n days while adhering to the given constraints.


Example:
limit = 7 primary = [4, 5, 2, 4] secondary = [5, 6, 3, 4].
One of the optimal scheduling can be:
• Day 1: Schedule the first primary task and the third secondary task. Total time is 4 + 3 = 7.
• Day 2: Schedule the second primary task. Total time is 5.
• Day 3: Schedule the third primary task and first secondary task. Total time is 2 + 5 = 7.
• Day 4: Schedule the fourth primary task. Total time is 4.
There is no other arrangement of secondary tasks for which more than 2 secondary tasks can be scheduled in 4 days.
Therefore, the maximum number of secondary tasks that can be scheduled during these 4 days is 2.


Function Description Complete the function getMaximum Tasks in the editor below.
*/
int getMaximum(int limit, vector<int> &primary, vector<int> &secondary){
    
    int n = primary.size();
    vector<int> re(n, 0);
    for(int i = 0; i < n; ++i){
        re[i] = limit - primary[i];
    }
    
    sort(re.begin(), re.end());
    sort(secondary.begin(), secondary.end());
    int count = 0;
    while(!re.empty() && !secondary.empty()){
        
        if(re.back() >= secondary.back()){
            count++;
            re.pop_back();
        }
        secondary.pop_back();
    }
    return count;
}
/*
Amazon Music is working on harmonizing their music playlist.
In their playlist system, each song is represented by a binary string music, where '0' and '1' denote two different types of music, say TypeA and TypeB. An "alternating music string" is one where no two adjacent songs are of the same type. For example, "1", "0", "10", "01", "101" are alternating music strings.
Given a binary string music representing the playlist and an integer k, you can perform up to k-operations where each operation involves flipping a character, i.e., turning '0' into '1' and '1' into '0'.
As a developer at Amazon, the task is to determine the longest alternating substring that can be created from the music string by performing at most k operations.
Note:
• A binary string is a sequence of '0' and '1' characters.
• A string A is a substring of a string B if A can be obtained from B by deleting several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.


Example
music = "1001" k = 1
By flipping the third character, the string becomes music = "1011". The longest alternating music string in this modified string is "101", which spans from the 0th index to the 2nd index and has a length of 3. With only one operation, it is not possible to obtain a longer alternating binary substring. Thus, the answer is 3.
Function Description Complete the function getMaxAlternatingMusic in the editor below.
*/
char flip(char b){
    return (b == '0') ? '1' : '0';
}
int getMaxAlternatingMusic(string &music, int k){
    int n = music.length();
    string mask1;
    char b = '0';
    for(int i = 0; i < n; ++i){
        mask1.push_back(b);
        b = flip(b);
    }
    
    int count1 = 0, ans;
    for(int i = 0; i < n; ++i){
        if(mask1[i] == music[i]) ++count1;
    }
    ans = max(count1, n-count1) + k;
    return ans > n ? n : ans;
}
int main() {
    int limit = 7;
    vector<int> primary = {4, 5, 2, 4};
    vector<int> secondary = {5, 6, 3, 4};
    cout << getMaximum(limit, primary, secondary) << endl;
    
    string music = "1001";
    int k = 1;
    cout << getMaxAlternatingMusic(music, k) << endl;
    
    music = "1000001";
    k = 2;
    cout << getMaxAlternatingMusic(music, k) << endl;
}