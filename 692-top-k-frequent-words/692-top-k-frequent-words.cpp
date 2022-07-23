class comp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;

        priority_queue<pair<int,string>, vector<pair<int,string>>, comp> pq;
        for(auto &x : words){
            mp[x]++;
        } 
        for(auto &m : mp){
            // cout << m.first << " " << m.second << endl;
            pq.push({m.second,m.first});
        }
        words.clear();
        while(k--){
            auto t = pq.top();
            pq.pop();
            words.push_back(t.second);
        }
        return words;
    }
};