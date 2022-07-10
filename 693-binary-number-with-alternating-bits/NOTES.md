bool hasAlternatingBits(int n) {
for(int i=0;i<31;i++){
int right = n&(1<<i);
int left = n&(1<<(i+1));
cout << left << " " << right;
if((left^right)==0){
return false;
}
cout << endl;
}
return true;
}