class Solution {
public:
    unordered_map<string, vector<string>> G;  
    vector<vector<string>> ans;
    unordered_set<string> vis;              
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {        
        
        build_graph(A);
        
        for(auto& x : A){
            // if this email is unvisited
            if(!vis.count(x[1])){
                vector<string> v;
                v.push_back(x[0]);
                dfs(x[1],v);
                sort(v.begin()+1,v.end());
                ans.push_back(v);
            }
                
        }       
        return ans;
    }
    void dfs(string& email,vector<string> &v) {
        v.push_back(email);
        vis.insert(email); 
        for(auto &ch : G[email]){
            if(!vis.count(ch)){
                dfs(ch,v);
            }
        }
    }
    
    void build_graph(vector<vector<string>>& A){
        for(auto& x : A)                            
            for(int i = 2; i < x.size(); i++)           
                G[x[i]].push_back(x[i-1]),             
                G[x[i-1]].push_back(x[i]);
    }
};