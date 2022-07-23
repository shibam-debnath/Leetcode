class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto &x : arr){
            mp[x]++;
        }
         
        priority_queue<int> pq;
        for(auto &m : mp){
            pq.push(m.second);
        }
        
        int half = (n+1)/2;
        int res=0 , sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
            res++;
            if(sum>=half) return res;
        }
        return res;
    }
};