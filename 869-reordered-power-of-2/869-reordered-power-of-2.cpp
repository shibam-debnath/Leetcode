class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string given_no = to_string_and_sort(n);
        for(int i=0;i<30;i++){
            int pow_2 = (1<<i);
            string pow_of_2 = to_string_and_sort(pow_2);
            if(given_no == pow_of_2) return true;
        }
        return false;
    }
    
    string to_string_and_sort(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    
};