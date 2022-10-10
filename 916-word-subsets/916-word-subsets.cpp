class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<char,int> mp;
        
        for(auto w : words2){
            vector<int> t(26,0);
            for(auto &c : w){
                t[c-'a']++;
                mp[c]= max(mp[c],t[c-'a']);                 
            }    
        }
        
        vector<string> ans;
        
        for(auto w : words1){
            
            unordered_map<char,int> np;
            
            for(auto &c : w){
                np[c]++;
            } 
            
            if(isSubset(mp,np)){
                ans.push_back(w);
            }
        }
        
        return ans;
    }
    
    bool isSubset(unordered_map<char,int>&b, unordered_map<char,int> &a){
        for(auto m : b){
            if(m.second > a[m.first])
                return false;
        }
        return true;
    }
};