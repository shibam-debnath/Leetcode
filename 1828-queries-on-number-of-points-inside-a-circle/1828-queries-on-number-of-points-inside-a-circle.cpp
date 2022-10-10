class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto t : queries){
            int x=t[0];
            int y=t[1];
            int r=t[2];
            
            int c=0;
            for(auto p : points){
                if(((x-p[0])*(x-p[0]) + (y-p[1])*(y-p[1]))<=r*r) c++;
            }
            res.push_back(c);
        }
        return res;
    }
};