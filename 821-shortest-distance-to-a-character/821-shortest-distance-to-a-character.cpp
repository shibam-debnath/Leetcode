class Solution
{
    public:
        vector<int> shortestToChar(string s, char c)
        {
            int n = s.size();
            vector<int> v(n, 0);

            int pos = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c)
                {
                    pos = i;
                    v[i] = 0;
                }
                if (pos != -1) v[i] = i - pos;

            }

           	// reverse check
            pos = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == c) pos = i;
                if (pos != -1)
                {
                    if (v[i] != 0) v[i] = min(v[i], abs(i - pos));
                    
                    else v[i]=abs(i-pos);
                    
                }
            }
            return v;
        }
};
