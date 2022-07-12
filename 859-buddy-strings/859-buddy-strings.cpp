class Solution {
public:
    
    bool buddyStrings(string s, string goal) {
        
        int n = s.size();
        int m=goal.size();
        
        if(n==1 || m!=n) return false;
        
        unordered_map<char,int> mp;
        
        if(n==2) return swap_check(s,goal);
        
        string a,b;
        int c=0;
        
        for( int i=0;i<n;++i){
            mp[s[i]]++;
            if(s[i]!=goal[i]){
                c++;
                if(c>2) return false;
                a.push_back(s[i]);
                b.push_back(goal[i]);
            }
        }
        
        // hanle same string
        if(s==goal){
            for(auto &m : mp){
                if(m.second>=2) return true;
            }
            return false;
        }
        
        // 2 diff char 
        if(c==2) return swap_check(a,b);
        
        // other cases eg - one/3 diff char
        return false;
    }
    
    bool swap_check(string &a,string &b){
        swap(a[0],a[1]);
        return a==b;
    }

};