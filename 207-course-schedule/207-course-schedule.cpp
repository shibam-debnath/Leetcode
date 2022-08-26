class Solution
{
public:
    bool canFinish(int N, vector<vector<int>> &P)
    {

        vector<vector<int>> G(N); 
        vector<int> ans, indegree(N);    
        
        for(auto& pre : P){
            G[pre[1]].push_back(pre[0]),       
            indegree[pre[0]]++;
        }
                                 
        queue<int> q;
        
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            
            auto t = q.front();q.pop();
            ans.push_back(t);
            
            for(auto ch : G[t]){
                indegree[ch]--;
                if(indegree[ch]==0){
                    q.push(ch);
                }
            }
        }
    
       if(ans.size()==N) return true;
       return false;
    }
    
};