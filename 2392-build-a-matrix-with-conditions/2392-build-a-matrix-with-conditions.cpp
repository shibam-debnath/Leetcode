class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        
        vector<int> r = topo(k,rc);
        vector<int> c = topo(k,cc);
        
        // for(int i=0;i<r.size();i++){
        //     cout << r[i] << " " << c[i] << endl;
        // }
        
        if(r.size()!=k or c.size()!=k) return {};
        
        vector<vector<int>> res(k,vector<int>(k,0));
        unordered_map<int,int> col_mp;
        
        for(int i=0;i<c.size();i++){
            col_mp[c[i]] = i;
        }
        
        for(int i=0;i<r.size();i++){
            int r_idx = i;
            int c_idx = col_mp[r[i]];
            res[r_idx][c_idx] = r[i];
        }
        return res;
    }
    
    vector<int> topo(int k,vector<vector<int>>& G){
        vector<vector<int>> graph(k+1);
        vector<int> indegree(k+1,0),v;
        for(auto r : G){
            indegree[r[1]]++;
            graph[r[0]].push_back(r[1]);
        }
        queue<int> q;
        for(int i=1;i<k+1;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            v.push_back(curr);
            for(auto ch : graph[curr]){
                if(--indegree[ch]==0){
                    q.push(ch);
                }
            }
        }
        return v;
    }
    
    
};