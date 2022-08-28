class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> G(n);
        for(auto f : flights){
            G[f[0]].push_back({f[1],f[2]});
        }
        
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        // cost  node stops
        pq.push({0,src,0});
        
        while(!pq.empty()){
                
                auto curr = pq.top();
                int cost = curr[0];
                int node = curr[1];
                int stops = curr[2];
                pq.pop();
                
                if(node==dst) return cost;
                if(stops>k) continue;
            
                if(dist[node]!=INT_MAX and dist[node]<stops) continue;
                dist[node] = stops; 
                
                for(auto &ch : G[node]){
                    int ch_node = ch.first;
                    int temp_cost = cost + ch.second;

                    pq.push({temp_cost,ch_node,stops+1});
                    
                }
        }
        
        return -1;
    }
};