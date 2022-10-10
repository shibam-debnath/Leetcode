class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
        // set<string> st; // visited
        unordered_map<string,bool> words,st;
        
        for(string s:wordList)
            words[s]=true;
        
        q.push(beginWord);
        st[beginWord] = true;
        
        int res=0;
        
        while(q.size()){
            int n = q.size();
            res++;
            while(n--){
                
                string s = q.front();
                q.pop();
                
                if(s==endWord)
                    return res;
                
                string t;
                // IN EACH POSITION OF STRING try replacing the char with a to z
                for(int i=0;i<s.size();i++){
                    t=s;
                    for(int j='a';j<='z';j++){
                        t[i]=j;
                        if(words.count(t) and !st.count(t)){
                            q.push(t);
                            st[t] = true;
                        }
                    }
                }
            }
        }
        return 0;
        
    }

};