class Solution
{
    public:
        string reverseWords(string s)
        {
            int i = 0;
            string t;
            int j = 0;
            int n = s.size();
            
            while(i<n){
                while(i<n and s[i]==' '){
                    i++;
                }
                j=i;
                while(i<n and s[i]!=' '){
                    i++;
                }
                // we found the word;
                t = s.substr(j,i-j)+" "+ t ;
            }
            i=0;
            while(t[i]==' '){
                t=t.substr(1);
            }
            i=t.size()-1;
            
            while(t[i]==' '){
                t.pop_back();
            }
            return t;
        }
};