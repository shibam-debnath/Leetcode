class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &mat)
        {
            vector<int> res;
            int n = mat.size(), m = mat[0].size();
            int left = 0, right = m - 1, top = 0, bot = n - 1;
            int dir = 0;

            while (left <= right && top <= bot){
                if (dir == 0){
                    for (int i = left; i <= right; i++){
                        res.push_back(mat[top][i]);
                    }
                    top++;
                    dir = (dir + 1) % 4;
                }
                else if(dir==1){
                    for (int j = top; j <= bot; j++){
                        res.push_back(mat[j][right]);
                    }
                    right--;
                    dir = (dir + 1) % 4;
                }
                else if (dir == 2){
                    for (int i = right; i >=left; i--){
                        res.push_back(mat[bot][i]);
                    }
                    bot--;
                    dir = (dir + 1) % 4;
                }
                else if(dir==3){
                    for (int j = bot; j >= top; j--){
                        res.push_back(mat[j][left]);
                    }
                    left++;
                    dir = (dir + 1) % 4;
                }
            }
            
            return res;
        }
};