class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> set;
        for(auto w : words){
            string single;
            for(auto &c : w){
                single+=codes[c-'a'];
            }
            set.insert(single);
        }
        return set.size();
    }
};