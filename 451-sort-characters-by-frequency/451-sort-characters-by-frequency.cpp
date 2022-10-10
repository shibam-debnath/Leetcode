class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> map;
    priority_queue<pair<int,char>> pq;

    for (auto &c : s)  map[c]++;
    s.clear(); 

    for(auto &it : map) pq.push({it.second, it.first});

    while(!pq.empty()){
        int freq = pq.top().first;
        char c = pq.top().second;
        pq.pop();
        while(freq--){
            s.push_back(c);
        }
    }
    return s;
    }
};