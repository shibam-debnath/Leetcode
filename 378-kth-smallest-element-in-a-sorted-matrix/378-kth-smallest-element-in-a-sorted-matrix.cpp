class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count = 1;
        
        priority_queue<int> pq;
        
        for(auto c : matrix){
            for(auto x : c){
                pq.push(x);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};