class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            unordered_map<string, int> mp;
            string s;
            int c = 0;
            for (auto &w: words) mp[w]++;

            bool flag = false;

            for (auto &m: mp)
            {
                s = m.first;
                reverse(s.begin(), s.end());
                
                if (s == m.first)
                {
                    // cout << "same" << endl;
                   	// if odd freq exists
                    if (m.second%2==1) {
                        flag=true;
                        c += 2*(m.second-1);
                    }
                    else{
                        c += 2*m.second;
                    }
                }
                else if (mp.find(s) != mp.end())
                {
                    // cout << "ulta found" << endl;
                    int a = m.second;
                    int b = mp[s];
                    c += (4* min(a, b));
                    mp.erase(s);
                }
            }
            
            if(flag==true){
                // cout << c << " ";
                return c+2;
            } 
            
            return c;
        }
};