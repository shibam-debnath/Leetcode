class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> v(10);
        int n=s.size(),i=0,mx_pos=0;
        
        while(i<n){
            string str="";
            while(!isdigit(s[i])){
                str.push_back(s[i]);
                i++;
            }
            int pos = s[i]-'0';
            mx_pos=max(pos,mx_pos);
            v[pos] = str;
            i=i+2; // digit + space
        }
        
        s.clear();
        
        for(int i=1;i<=mx_pos;i++){
            if(i==mx_pos){
                s+=v[i];
                return s;
            }
            s+=v[i]+" ";
        }
        return "";
    }
};