class Solution
{
public:
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    int orangesRotting(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int fresh = 0;
        int time =0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.emplace(i,j);
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        
        while(!q.empty()){
            
            int size = q.size();
            ++time;
            
            while(size--){
                auto t = q.front();
                int x = t.first;
                int y = t.second;
                q.pop();
                
                for(auto d : dir){
                    
                    int X = x+d.first;
                    int Y = y+d.second;
                    
                    if( X<0 or X>=n or Y<0 or Y>=m or grid[X][Y] == 0 or grid[X][Y] == 2) continue;
                    
                    q.emplace(X,Y);
                    grid[X][Y] = 2;
                    
                    
                    fresh--;
                    
                }
            }
        }
        
        if(fresh!=0) return -1;     
        if(time == 0) return 0;
        return time-1;

    }
};