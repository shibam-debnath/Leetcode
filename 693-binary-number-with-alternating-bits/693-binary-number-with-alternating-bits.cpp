class Solution
{
    public:
        bool hasAlternatingBits(int n)
        {
            int flag = n&1;
            while (n) {
                n= n>>1;
                int curr = n&1;
                if(curr == flag)  return false;
                flag = curr;
            }
            return true;
        }
};