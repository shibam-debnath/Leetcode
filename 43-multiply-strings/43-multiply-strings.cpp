class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(),m=num2.size();
        vector<int> ans(n+m,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                // first multiply and store the val+previously stored val in the pos
                ans[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                // since we need to store only the last ele here
                // store num/10(remaining val) in usse pehle pos mein
                ans[i+j] += ans[i+j+1]/10;
                // waha bas first digit ko rakho
                ans[i+j+1] = ans[i+j+1]%10;
            }
        }
        num1.clear();
        int i=0;
        while(ans[i]==0 && i!=ans.size()-1) i++;
        while(i<ans.size()){
            num1+=(ans[i]+'0');
            i++;
        }
        return num1;
    }
};