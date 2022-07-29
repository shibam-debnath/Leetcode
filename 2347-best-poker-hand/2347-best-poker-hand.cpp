class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char,int> suit;
        unordered_map<int,int> rank;
        
        bool three = false , pair = false;
        
        for(auto x : ranks) rank[x]++;
        
        for(auto x : suits) suit[x]++;
        
        if(suit.size()==1){
            return "Flush";
        }
        
        for(auto m : rank){
            if(m.second >= 3){
                three=true;
            }
            else if(m.second >= 2){
                pair = true;
            }
        }
        
        if(three==true) return "Three of a Kind";
        else if(pair==true) return "Pair";
        return "High Card";
        
    }
};