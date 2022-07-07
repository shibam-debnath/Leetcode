class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long product = nums[n-1]*nums[n-2]*nums[n-3];
        
        if(nums[0]<0 && nums[1]<0 && nums[n-1]>0){
            long long this_product = nums[0]*nums[1]*nums[n-1];
            product=max(product,this_product);
        }
        
        return product;
    }
};