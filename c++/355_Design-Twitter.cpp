class Twitter {
public:
    class User {
    public:
        int userId;
        set<int>followers;
        vector<pair<int,int>> recentPosts; // first: timestamp, second: tweetId
        User(int id){
            userId = id;
            followers.insert(id); // Users must follow themselves
        }
    };

    unordered_map<int,User*> accounts;
    int timestamp;
    int feedLimit=10;
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        // check if account exists
        if(!accounts.count(userId)) accounts[userId] = new User(userId);

        User* user = accounts[userId];
        user->recentPosts.push_back(pair<int,int>(timestamp, tweetId));
        ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        // check if account exists
        if(!accounts.count(userId)) accounts[userId] = new User(userId);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> feed; // min heap

        User* user = accounts[userId];
        for(auto iteration=user->followers.begin(); iteration != user->followers.end();++iteration){
            int follwerId = *iteration;
            if(!accounts.count(follwerId)) accounts[follwerId] = new User(follwerId);

            User* follower = accounts[follwerId];
            int size = follower->recentPosts.size();
            for(int tailIndex = size-1; tailIndex>=0 && tailIndex>=size-feedLimit; --tailIndex){
                // Feed reaches feedLimit. The added post should be earlier than top one(oldest) in the feed
                if(feed.size()==feedLimit){
                    if(follower->recentPosts[tailIndex].first < feed.top().first) break;
                }

                feed.push(follower->recentPosts[tailIndex]);
                if(feed.size()>feedLimit) feed.pop();
            }
        }

        vector<int> feed_vec;
        // feed_vec stores in ordered from least recent to most recent since feed is a MIN HEAP
        while(!feed.empty()){
            feed_vec.push_back(feed.top().second);
            feed.pop();
        }
        reverse(feed_vec.begin(), feed_vec.end());
        return feed_vec;
    }
    
    void follow(int followerId, int followeeId) {
        // check if both accounts exist
        if(!accounts.count(followerId)) accounts[followerId] = new User(followerId);
        if(!accounts.count(followeeId)) accounts[followeeId] = new User(followeeId);


        User* user = accounts[followerId];
        user->followers.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // check if both accounts exist
        if(!accounts.count(followerId)) accounts[followerId] = new User(followerId);
        if(!accounts.count(followeeId)) accounts[followeeId] = new User(followeeId);

        User* user = accounts[followerId];
        user->followers.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */