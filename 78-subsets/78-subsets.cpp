class Solution {
public:
    void show_subset(vector<int> &subset,vector<int>& nums,int i,vector<vector<int>> &subsets_all){

    //base case
    if (i >= nums.size())
    {
        subsets_all.push_back(subset);
        return;
    }
        
    //decision space : here at beginning pos we can choose only current element 
    //                 not all the element like permutation problem
        

    //adding the element
    subset.push_back(nums[i]);
    show_subset(subset,nums,i+1,subsets_all);
    subset.pop_back();
        
    // not adding the element
    show_subset(subset,nums,i+1,subsets_all);  
        
  }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        //to store each subsets
        vector<int> subset;
        
        //to store all subsets
        vector<vector<int>> subsets_all;
        
        show_subset(subset,nums,0,subsets_all); 

        return subsets_all;
    }
};