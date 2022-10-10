string longestCommonPrefix(vector<string>& strs) {
if ( strs.size() == 0){
return "";
​
}
string s = strs[0];
int j=0;
for(int i=1;i<strs.size();i++){
for(j = 0; j < strs[i].size(); j++) {
if(s[j] != strs[i][j])
break;
}
s = s.substr(0, j);
}
return s;
}