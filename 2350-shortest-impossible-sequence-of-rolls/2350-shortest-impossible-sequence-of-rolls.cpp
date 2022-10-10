class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,int> mp;
        int target = 1; // target length of shortest subseq of rolls
        for(auto x : rolls){
            mp[x]++;
            if(mp.size()==k){
                target++;  // since now we can form all subseq of rolls of length target  
                mp.clear(); 
            }
        }
        return target;
    }
};