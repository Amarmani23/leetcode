class Twitter {
private:
    int timestamp;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>following;

public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>maxHeap;
        following[userId].insert(userId);
        for(int followeeId : following[userId]){
            if(tweets.count(followeeId) && !tweets[followeeId].empty()){
                int lastIdx=tweets[followeeId].size()-1;
                auto [time,tweetId]=tweets[followeeId][lastIdx];
                maxHeap.push({time,tweetId,followeeId,lastIdx});
            }
        }
        vector<int>feed;
        while(!maxHeap.empty() && feed.size()<10){
            auto top=maxHeap.top();
            maxHeap.pop();

            int tweetId=top[1];
            int followeeId=top[2];
            int idx=top[3];

            feed.push_back(tweetId);
            if (idx > 0) {
                auto [prevTime, prevTweetId] = tweets[followeeId][idx - 1];
                maxHeap.push({prevTime, prevTweetId, followeeId, idx - 1});
            }
        }

        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
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