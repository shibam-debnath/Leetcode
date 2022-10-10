class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        int cost = 0;
        //store freq
        for(auto &c : s){
            freq[c - 'a']++;
        }
        //sort the array for optimization
        sort(freq.begin(), freq.end());
        // now traverse and check if freq match or not. if matches find a suitable position in the array
        for (int i = 24; i >= 0; i--) // We dont need to change the greatest element so start from 24 not 25
        {
            if(freq[i]==0){
                break;
            }

            if(freq[i] >= freq[i+1]){
                int old_freq = freq[i];
                freq[i] = max(0, freq[i + 1] - 1); // but to calculate the cost we need old frq and updated freq , that;'s why we store the old frq in a var
                int new_freq = freq[i];

                cost += old_freq - new_freq;
            }
        }
        return cost;
    }
};