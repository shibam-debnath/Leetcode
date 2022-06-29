class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m,n;
        
        for(auto num1 : nums1){
            m[num1]++;
        }
        for(auto &num2 : nums2){
            n[num2]++;
        }
        
        for(auto x : nums1){
            if(m[x]>0 && n[x]>0){
                ans.push_back(x);
                m.erase(x);
            } 
        }
        return ans;
    }
};