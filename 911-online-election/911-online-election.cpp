class TopVotedCandidate {
public:
    map<int,int> winner;
    int champ=-1,mx_vote=-1;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int,int> mp;
        for(int i=0;i<times.size();i++){
            mp[persons[i]]++;
            if(mp[persons[i]]>=mx_vote){
                mx_vote = mp[persons[i]];
                champ = persons[i];
            }
            winner[times[i]]=champ;
        }
    }
    
    int q(int t) {
        auto it = winner.upper_bound(t);
        if(it->first!=t) it--;
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */