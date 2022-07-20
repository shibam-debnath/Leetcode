class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            int count = 0, k = s.size();
            unordered_map<string, int> mymap;
            for (int i = 0; i < words.size(); i++){
                mymap[words[i]]++;
            }

            for (auto x: mymap)
            {
                int i = 0, j = 0;
                string p = x.first;
                int m = p.size();
                while (i < k && j < m)
                {
                    if (p[j] == s[i])
                        i++, j++;
                    else
                        i++;
                }
                if (j == m)
                    count += x.second;
            }
            return count;
        }
};