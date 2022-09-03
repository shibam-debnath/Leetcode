class Twitter {
private:    
    unordered_map<int,unordered_set<int>> frnd; // user -> his friends. NOTE : set becoz all friends should be unique
    unordered_map<int,deque<pair<int,int>>> user_posts; // user -> 10 recent posts in deque
    int time = 0;
    
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId){
        // insert posts to respective userId
        user_posts[userId].push_back({time++,tweetId});
        // we'll store at max 10 posts for each person
        if(user_posts[userId].size()>10){
            user_posts[userId].pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        // priority_queue to easily get recent posts
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
        
        // take only 10 recent posts
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            if(res.size()==10) return res;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // add to friendList
        frnd[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = frnd[followerId].find(followeeId);
        // erase only if followeeId exists
        if(it!=frnd[followerId].end()){
            frnd[followerId].erase(it);    
        }
    }
};
