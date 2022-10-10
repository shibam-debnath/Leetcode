class Solution {
public:
    int maximumRobots(vector<int>& cc, vector<int>& rc, long long budget) {
        int n=rc.size();
        int end=0;
        
        long long sum = 0;
        int res=0; 
        int start=0;
        priority_queue<pair<int,int>> pq;
        
        while(end<n){
            
            pq.push({cc[end],end});
            while(pq.top().second < start) pq.pop();
            
            sum+=rc[end];
            int mx = pq.top().first;
            int size = end-start+1;
            
            long long curr_cost = mx + (size*sum);
            
            // cout << mx << " " << size <<" " <<  sum << " " << curr_cost << endl;
        
            while(size and curr_cost>budget){
                // cout << mx << " " << size <<" " <<  sum << " " << curr_cost << endl;
                sum-=rc[start];
                size--;
                while(pq.top().second < start) pq.pop();
                if(!pq.empty()){
                    mx = pq.top().first;
                } 
                curr_cost = mx+(size*sum);
                // cout << curr_cost << endl;
                start++;
            }
            
            if((end-start+1)>res and curr_cost<=budget){
                res=end-start+1;
            }
            end++;
        }
        
        return res;
        
    }
};