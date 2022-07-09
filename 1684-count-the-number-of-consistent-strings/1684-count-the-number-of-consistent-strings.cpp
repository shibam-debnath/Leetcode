class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto &c : allowed){
            mp[c]++;
        }
        
        int count=0;
        int n=words.size();
        
        for(auto s : words){
            for(auto &x : s){
                if(mp.find(x)==mp.end()){
                    // cout << x << " ";
                    count++;
                    break;
                }
            }
        }
        // cout <<endl <<  n << " "<< count;
        return n-count;
        
    }
};