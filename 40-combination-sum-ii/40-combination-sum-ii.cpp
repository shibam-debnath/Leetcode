class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // to store each subsets
        vector<int> subset;

        // to store all subsets
        vector<vector<int>> subsets_all;
        
        
        sort(candidates.begin(),candidates.end());
        
        combination_sum(subset,candidates, target,0, subsets_all);
        
        
        return subsets_all;
        
    }
    
    void combination_sum(vector<int> &subset, vector<int>& candidates, int t,int index, vector<vector<int>> &subsets_all)
    {
        
        if(t==0){
            subsets_all.push_back(subset);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if(candidates[i]>t) continue;
            if(i!=0 && candidates[i]==candidates[i-1] && i>index) continue; // this trick (IMPORTANT)
            
            subset.push_back(candidates[i]);
            combination_sum(subset,candidates, t-candidates[i],i+1, subsets_all);
            subset.pop_back();
        }
    }
};  