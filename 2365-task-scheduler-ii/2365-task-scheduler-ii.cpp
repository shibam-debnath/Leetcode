class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> mp;
        long long curr_day=0;
                
        // mp stores next possible day to perform a task
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])!=mp.end()){
                curr_day = max(curr_day, mp[tasks[i]]);
            }
            mp[tasks[i]] = curr_day+space+1;
            curr_day++;
            
        }
        return curr_day;
    }
};