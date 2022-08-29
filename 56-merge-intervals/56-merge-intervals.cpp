class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &v)
        {
            sort(v.begin(), v.end());

            vector<vector < int>> ans;
            ans.emplace_back(v[0]);
            
            int l = ans[0][0];
            int r = ans[0][1];

            int k = 0;

            for (int i = 1; i < v.size(); i++)
            {
                if(v[i][0] <= r){
                    
                    int mx = max(v[i][1],r);
                    int mn = min(v[i][0],l);
                    
                    ans[k][0] = mn;
                    ans[k][1] = mx;
                    
                    l = mn;
                    r = mx;
                }
                else{
                    ans.emplace_back(v[i]);
                    
                    l = v[i][0];
                    r = v[i][1];
                    
                    k++;
                }
            }
            return ans;
        }
};