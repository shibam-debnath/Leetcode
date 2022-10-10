class Solution
{
    
    // Time Complexity :::  O(4^n)
    // Space Complexity ::: O(n)
public:
    #define ll long long

    bool helper(vector<int> &solai, int idx, vector<ll> &sides)
    {
        if (idx == solai.size()){
            for(auto &x : sides){
                if(x!=0) return false;
            }
            return true;
        }
            

        for (int i = 0; i < 4; i++)
        {
            if (solai[idx] > sides[i]) continue; // we don't take this vak

            sides[i] = sides[i] - solai[idx]; // take
            if (helper(solai, idx + 1, sides)) return true;
            sides[i] = sides[i] + solai[idx]; // backtracking part
        }
        return false;
    }

    bool makesquare(vector<int> &solai)
    {
        if (solai.size() < 4) return false;
        
        ll sum = accumulate(solai.begin(), solai.end(), 0);
        
        if (sum % 4 != 0) return false;
        
        ll len = sum / 4;

        vector<ll> sides{len,len,len,len};
        sort(solai.begin(),solai.end(),greater<int>());
        
        return helper(solai, 0, sides);
    }
};