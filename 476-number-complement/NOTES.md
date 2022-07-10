int findComplement(int num) {
int c=31;
while(c>=0 && (num&(1<<c))==0){
//reach first 1
c--;
}
// toggle every bit from here
while(c>=0){
num = num^(1<<c);
c--;
}
return num;
}