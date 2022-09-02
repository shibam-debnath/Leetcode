class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int gap)
        {
            
            unordered_map<char, int> mp;
            priority_queue<int> pq;
            for (auto &x: tasks) mp[x]++;
            
            for(auto m : mp){
                pq.push(m.second);
            }
            
            int time=0;
            
            
            while(!pq.empty()){
                vector<int> v;
                for(int i=0;i<=gap;i++){
                    if(pq.size()){
                        v.push_back(pq.top());
                        pq.pop();
                    }        
                }
                
                for(auto x :v){
                    if((--x)>0){
                        pq.push(x);
                    }
                }
                time += pq.empty() ? v.size() : gap+1;
            }
            
            return time;
        }   
};          