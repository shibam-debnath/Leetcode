class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gsize) {
        int n = hand.size();
        if (n % gsize != 0) return false;
        
        map<int, int> mp;
        for (auto &x: hand) ++mp[x];

        while(mp.size()!=0){
            
            int first = mp.begin()->first;
            for(int i=0;i<gsize;i++){
                if(!mp.count(first+i)) return false;
                --mp[first+i];
                if(mp[first+i]==0){
                    mp.erase(first+i);
                }
            }
        }
        return true;
    }
};