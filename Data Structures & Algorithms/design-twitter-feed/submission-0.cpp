class Twitter {
    int timeStamp;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timeStamp++, tweetId});
        if(tweetMap[userId].size()>10) tweetMap[userId].erase(tweetMap[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;
        followMap[userId].insert(userId);
        for(auto f: followMap[userId]){
            if(tweetMap.count(f)){
                all.insert(all.end(), tweetMap[f].begin(), tweetMap[f].end());
            }
        }
        sort(all.begin(), all.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        vector<int> rc;
        for (int i = 0; i < all.size() && i < 10; i++)
            rc.push_back(all[i].second);
        return rc;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};
