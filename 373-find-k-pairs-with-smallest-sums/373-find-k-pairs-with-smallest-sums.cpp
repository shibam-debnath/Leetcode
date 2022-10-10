class Solution {
public:
    typedef pair<int, pair<int, int>> pii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pii , vector<pii> , greater<pii>> pq;
        
        for(int i=0;i<nums1.size();i++) pq.push({nums1[i]+nums2[0] , {i,0}});
        
        vector<vector<int>> res;
        int i=0;
        while(k-- && !pq.empty()){
            
            // auto [i,j] : pq.top().second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            res.push_back({nums1[i],nums2[j]});
            pq.pop();
            
            if(j<nums2.size()-1){
                pq.push({nums1[i]+nums2[j+1] , {i,j+1}});
            }
        }
        return res;
    }
};