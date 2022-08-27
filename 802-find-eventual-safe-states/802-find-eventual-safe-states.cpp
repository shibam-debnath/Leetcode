class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int>res, indegree(n,0);
        vector<vector<int>> revG(n);
        
        int i=0;
        for(auto row : graph){
            for(auto x : row){
                revG[x].push_back(i);
                indegree[i]++;
            }
            i++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            auto curr = q.front();q.pop();
            res.push_back(curr);
            for(auto &ch : revG[curr]){
                indegree[ch]--;
                if(indegree[ch]==0) q.push(ch);
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};