class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &groupSizes)
        {
            vector<vector < int>> res;
            unordered_map<int, vector < int>> mp;
            for (int i = 0; i < groupSizes.size(); i++)
            {
                mp[groupSizes[i]].push_back(i);
            }

            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                int pos = i->first;
               	cout << pos << endl;
                for (int i = 0; i < mp[pos].size(); i++)
                {
                    vector<int> temp;
                    // cout << i << " ";
                    for (int j = i; j < i+pos; j++)
                    {
                        
                        temp.push_back(mp[pos][j]);
                    }
                    // cout << i << " ";
                    i += (pos-1);
                    // cout << i << endl ;
                    res.push_back(temp);
                }
            }
                
            return res;
        }
};