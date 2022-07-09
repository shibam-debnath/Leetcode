class Solution
{
    public:
     
    // since a^a == 0
    
        char findTheDifference(string s, string t)
        {
            char c = 0;
            for (auto x: s) c ^= x;
            for (auto y: t) c ^= y;
                
            return c;
        }
};