class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);

        // -1 ->red
        //  0 -> no clr
        //  1 ->blue
        
        // check for all unvisited nodes
        for(int i=0;i<n;i++){
            
            if(vis[i]) continue;
            
            queue<int> q;
            q.push(i);
            vis[i] = 1; // colored red

            while(!q.empty()){
                int size = q.size();
                while(size--){

                    auto par = q.front();
                    q.pop();

                    for(auto ch : graph[par]){

                        // already colored
                        if(vis[ch]!= 0){
                            if(vis[ch] == vis[par]) return false;
                        }
                        else{
                            q.push(ch);
                            vis[ch] = -vis[par];  // if par == 1 it becomes ch == 1 and vice versa
                        }
                    }
                }
            }
            
        }
        
        return true;
    }
    
    

};