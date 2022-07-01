class Solution
{
        // TWO pointer method 
    
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            int left=0,right = arr.size()-1;
            // keep removing from both side(using given condition) untill right-left +1 = k
            while(right-left+1 > k){
                // left dis <= right dis so take left distance
                if(x-arr[left] <= arr[right]-x){
                    //left lena h
                    right--;
                }
                else{
                    left++;
                }
            }
            // vector<int> ans(arr.begin()+left,ans.begin()+left+k);
            // return ans;
            vector<int> ans;
            for(int i=left;i<=right;i++){
                ans.push_back(arr[i]);
            }
            // ans.assign(arr.begin()+left,ans.begin()+right);
            return ans;
        }

};