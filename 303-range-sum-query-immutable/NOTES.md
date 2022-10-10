class NumArray {
public:
vector<int> v;
NumArray(vector<int>& nums) {
// assign nums val to v
v.assign(nums.begin(),nums.end());
}
int sumRange(int left, int right) {
return accumulate(v.begin()+left,v.begin()+right+1,0);
}
};
​