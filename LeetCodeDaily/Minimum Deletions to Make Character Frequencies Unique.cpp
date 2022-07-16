//Shibam Debnath
//June ,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        int cost = 0;
        //store freq
        for(auto &c : s){
            // a-> 0th position , b->1th position
            freq[c - 'a']++;
        }
        //sort the array for optimization
        sort(freq.begin(), freq.end());
        // now traverse and check if freq match or not. if matches find a suitable position in the array
        for (int i = 24; i >= 0; i--) // We dont need to change the greatest element so start from 24 not 25
        {
            if(freq[i]==0){
                // we are at the end no more char is there so break
                break;
            }

            if(freq[i] >= freq[i+1]){
                // they have same freq , now we can give it a freq less than prev one whicch must be greater than 0
                int old_freq = freq[i];
                freq[i] = max(0, freq[i + 1] - 1); // but to calculate the cost we need old frq and updated freq , that;'s why we store the old frq in a var
                int new_freq = freq[i];

                cost += old_freq - new_freq;
            }
        }
        return cost;
        // unordered_map<char, int> mp,freq;
        // // calculate freq
        // for(auto &c : s){
        //     mp[c]++;
        // }
        // // sort map on the basis of freq
        // int cost = 0;
        // for (auto &m : mp){
        //     freq[m.second]++;
        // }


        // for(auto &x : freq){
        //     if(x.second > 1){
        //         // repeating freq
        //         // find a freq which is not present
        //         for (int i = x.second - 1; i >= 0;i--){
        //             if(freq.find(i)!=freq.end()){
        //                 //continue because x exists
        //                 cost++;
        //             }
        //             else{
        //                 // this i is not present
        //                 cost = x.second - i;
        //                 x.second--;
        //             }
        //         }
        //     }
        // }
    }
};

int main() {
    //Main function goes here
    return 0;
}