class Solution {
public:
    int t[201][201];
    bool util(string s1, string s2, string s3,int i , int j , int k){
        if(k>=s3.size())
            return true;
        
        if(t[i][j]!=-1)
            return t[i][j];
        
        if(s1[i]==s3[k] && s2[j]==s3[k] && i<s1.size() && j<s2.size())
            return t[i][j] = util(s1,s2,s3,i+1,j,k+1) || util(s1,s2,s3,i,j+1,k+1);
        
        
        else if(s1[i]==s3[k] && i<s1.size())
            return t[i][j] = util(s1,s2,s3,i+1,j,k+1);
        
        
        else if(s2[j]==s3[k] && j<s2.size())
            return t[i][j] = util(s1,s2,s3,i,j+1,k+1);
        
        
        else
            return t[i][j] = false;
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1+n2!=s3.size())
            return false;
        
        memset(t,-1,sizeof(t));
        return util(s1,s2,s3,0,0,0);
    }
};