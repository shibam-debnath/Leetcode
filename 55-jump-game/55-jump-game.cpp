class Solution {
public:
   
    bool canJump(vector<int>& arr) {

        int n = arr.size();
        int var = 1 ;
        for(int i=0;i<n;i++){
            var--;
            if(arr[i] > var){
                var = arr[i];
            }
            if(var == 0 && i!=(n-1)) return false;
        }
        
        return true;
    }
};