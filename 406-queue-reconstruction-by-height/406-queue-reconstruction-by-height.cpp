class Solution {
public:
    
    
    static bool comp(vector<int> &v1 ,vector<int> &v2){
        // if they have different first val then insert based on first val->decreasing order
        if(v1[0]!=v2[0]){
            // we want first ka first val should be greater than 2nd ka first val
            return v1[0] > v2[0];
        }
        // if they are same, return based on second val->increasing order
        return v1[1] < v2[1]; 
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        // STEP 01 : sort
        sort(people.begin(),people.end(),comp);
        // STEP 02 : traverse and put them in right position using the second val
        for(int i=0;i<people.size();i++){
            //insert(pos,val)
            // pos == we want to insert to that particular row which is p[i][1] since we need an interator so 
            // pos = ans.begin()+p[i][1]
            // val ==  value is that row p[i]
            ans.insert(ans.begin()+people[i][1],people[i]);
        }
        return ans;
    }
};