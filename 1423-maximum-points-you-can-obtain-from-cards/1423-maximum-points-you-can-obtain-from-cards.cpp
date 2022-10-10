class Solution {
public:
    int maxScore(vector<int>& card, int k) {
    int n = card.size();
    int lSum =0;
        for(int i=0;i<k;i++){
            lSum+=card[i];
        }
        // we found left sliding window sum and now store masx and check other windows
        int maxVal =  lSum;
        cout <<  lSum << endl;
        for(int i=k-1;i>=0;i--){
            lSum-=card[i];
            lSum+=card[i+(n-k)];
            // cout <<  card[i] << " " << card[i+(n-k)] << endl ;
            
            maxVal= max(maxVal,lSum);
        }
        return maxVal;
    }
};