class Solution
{
    public:
    int steps = 0;
    bool isHappy(int n)
    {
        // cout << n << " ";
        if (steps > 31) return false;
        if (n == 1){
            return true;
        } 
        int num = 0;
        while (n > 0)
        {
            int rem = n % 10;
            num += rem * rem;
            n /= 10;
        }
        
        steps++;
        return isHappy(num);
    }
};