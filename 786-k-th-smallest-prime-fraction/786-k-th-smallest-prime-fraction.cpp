class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        priority_queue<pair<double,pair<int,int>>> pq;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction = (double)arr[i]/(double)arr[j];
                pq.push({fraction , {arr[i],arr[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        
        int res1 = pq.top().second.first;
        int res2 = pq.top().second.second;
        
        // cout <<  pq.top().first;
        
        return {res1,res2};
    }
};