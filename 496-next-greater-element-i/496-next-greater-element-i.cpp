class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n=nums1.size();
            int m=nums2.size();
            
            unordered_map<int,int> mp;
            for(int i=0;i<m;i++){
                for(int j=i+1;j<m;j++){
                    if(nums2[j]>nums2[i]){
                        mp[nums2[i]] = nums2[j];
                        break;
                    }
                    if(j==m) {
                        mp[nums2[i]] = -1;
                    }
                }
            }
            
            vector<int> v(n,-1);
            for(int i=0;i<n;i++){
                if(mp.find(nums1[i])!=mp.end()){
                    v[i] = mp[nums1[i]];
                }
            }
            return v;
        }
};