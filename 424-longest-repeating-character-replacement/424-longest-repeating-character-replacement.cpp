class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int start=0,end=0,max_freq=0,longest=0;
        int n=s.size();
        
        while(end<n){
            
            mp[s[end]]++;
            max_freq=max(max_freq,mp[s[end]]);
            
            int diff_char = (end-start+1)-max_freq;
            
            // if diff char exceeds k remove from beginning 
            while(diff_char > k){
                mp[s[start]]--;
                start++;
                diff_char = (end-start+1)-max_freq;
            }
            
            longest=max(longest,end-start+1);
            end++;
        }
        
        return longest;
    }
};