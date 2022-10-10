class Solution {
public:
    int addDigits(int num) {
        
        int digit_sum=0;
        while(num>0){
            digit_sum+=(num%10);
            num/=10;
        }
        // cout << " " << digit_sum << " ";
        if(digit_sum<10) return digit_sum;
            
        return addDigits(digit_sum);
    }
};