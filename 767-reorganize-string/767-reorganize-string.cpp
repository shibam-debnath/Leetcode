class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>> pq;
        unordered_map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto m : mp){
            pq.push({m.second,m.first});
        }
        s.clear();
        while(pq.size()>1){
            
            auto fir = pq.top();pq.pop();
            auto sec = pq.top();pq.pop();

            s.push_back(fir.second);
            s.push_back(sec.second);
            
            int size1 =fir.first;
            int size2 = sec.first;
            if(size1>1){
                size1--;
                pq.push({size1,fir.second});
            }
            if(size2>1){
                size2--;
                pq.push({size2,sec.second});
            }
        }
        
        if(pq.size() && pq.top().first==1){
            s.push_back(pq.top().second);
            pq.pop();
        }
        
        if(pq.size() && pq.top().first>1){
            return "";
        }
        
        return s;
    }
};