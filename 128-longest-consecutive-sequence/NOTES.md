class Solution
{
public:
int longestConsecutive(vector<int> &nums)
{
if(nums.size()==0){
return 0;
}
if(nums.size()==1){
return 1;
}
// unordered_map<int,int > mp;
sort(nums.begin(), nums.end());
​
int num = 1, max_n = 0;
for (int i = 1; i < nums.size(); i++)
{
if (nums[i] == nums[i - 1]) {
continue;
}
else if (nums[i] == nums[i - 1] + 1)
{
num++;
}
else
{
max_n = max(max_n, num);
num = 1;
}
}
return max(max_n,num);
}
};