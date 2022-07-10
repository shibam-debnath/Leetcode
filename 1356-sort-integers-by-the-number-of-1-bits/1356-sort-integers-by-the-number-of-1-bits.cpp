class Solution {
public:
    static bool com(int &a,int &b){
        int n =__builtin_popcountll(a);
        int m =__builtin_popcountll(b);
        
        if(n==m){
            return a<b;
        }
        return n<m ;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),com);
        return arr;
    }
};