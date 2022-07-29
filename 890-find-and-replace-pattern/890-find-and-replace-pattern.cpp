class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto w : words){
            
            unordered_map<char,char> mp,np;
            
            for(int i=0;i<w.size();i++){
                
                if(mp.find(pattern[i])!=mp.end()){
                    if(mp[pattern[i]]!=w[i]) break;
                }
                else if(np.find(w[i])!=np.end()){
                    if(np[w[i]]!=pattern[i]) break;
                }
                else{
                    mp[pattern[i]] = w[i];
                    np[w[i]] = pattern[i];
                }
                
                if(i==w.size()-1){
                    res.push_back(w);
                }
            }
        }
        
        return res;
    }
};