class Twitter {
public:
    
    #define pii pair<int,int>
    int time = 0;
    
    unordered_map<int,multiset<pii>> post; //  user-> time and post_id
    unordered_map<int,deque<pair<int,int>>> user_posts; // user -> 10 recent posts
    unordered_map<int,unordered_set<int>> frnd; // user -> his friends NOTE : set becoz all friends should be unique
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId){
        time++;
        user_posts[userId].push_back({time,tweetId});
        // we'll store at max 10 posts for each person
        if(user_posts[userId].size()>10){
            user_posts[userId].pop_front();
        }
        // mp[userId].insert({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        // own posts
        for(auto &posts : user_posts[userId]){
            pq.push(posts);
        }      
        // posts of friends
        for(auto f : frnd[userId]){
            for(auto v : user_posts[f]){
                pq.push(v);
            }  
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            if(res.size()==10) return res;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        frnd[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // if(frnd[followerId].count(followeeId)){
        //     frnd[followerId].erase(followeeId);
        // }
        auto it = frnd[followerId].find(followeeId);
        if(it!=frnd[followerId].end()){
            frnd[followerId].erase(it);    
        }
        // remove(frnd[followerId].begin(),frnd[followerId].end(),followeeId);
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