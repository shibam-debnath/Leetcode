class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,int> mp;
        for(auto x:d){
            mp[x]=1;
        } 
        string str;
        string ans;
        // Variable to check if the current substring is in map or not
        bool flag = true; 
        for(int i=0;i<=s.length();i++){
            // Make the flag true whenever find a space or end of sentence
            if(i == s.length() or s[i]==' '){
                str = "";
                flag = true;
            }
            else if(s[i]!=' '){
                // one by one add char of words
                str+=s[i];
            } 
            
            // whenever we find the word in map we just flag == false and no char goes to ans untill new word 
            if(mp[str] and flag){
                ans+=s[i];
                flag = false;
            }
            else if(flag and i!=s.length()) 
                ans+=s[i]; // Add the current char to answer if there was no match
        }
        
        return ans;
    }
};