class Solution {
public:
    int minSwaps(string s) {
        int open= 0, st =0;
        for(auto c : s){
            if(c=='[') st++;
            else if(c==']' and st>0){
                st--;
            }
        }
        return (st+1)/2;
    }
};