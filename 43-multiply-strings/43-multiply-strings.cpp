class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        
        vector<int> res(n+m,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                res[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                int sum = res[i+j+1];
                res[i+j] += sum/10;
                res[i+j+1] = sum%10;
            }
        }
        
        // remove leading zeros
        int k=0;
        while(res[k]==0 && k!= res.size()-1){
            k++;
        }
        
        num1.clear();
        while(k<res.size()){
            num1+=(res[k]+'0');
            k++;
        }
        
        return num1;
    }
};