class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
            if(n<0) return false;
            int no = __builtin_popcount(n);
            return no==1;
        }
};