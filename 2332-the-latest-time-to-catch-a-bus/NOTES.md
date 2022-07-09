class Solution
{
public:
int latestTimeCatchTheBus(vector<int> &buses, vector<int> &p, int capacity)
{
unordered_map<int,int> mp;
priority_queue<int,vector<int>,greater<int>> bus,pass;
int last_pass=0,result =0;
for(auto b : buses){
bus.push(b);
}
for(auto arr_time : p){
pass.push(arr_time);
mp[arr_time]++;
}
while(!bus.empty()){
int c=0;
while( c<capacity && pass.top()<=bus.top() && pass.empty()==false){
last_pass = pass.top();
pass.pop(); // store it
// also store the arrival time of last passenger since we have to go before him
if(mp.find(last_pass-1)==mp.end()){
result = last_pass-1;
cout << result << " ";
}
c++;
}
// suppose for this bus departure time is 10 and our last_passenger is 3
// In this case our ans is 10 because we want the latest time to catch the bus
if(last_pass < bus.top() && c < capacity){
cout << endl << c << " " << last_pass << endl;
result = bus.top();
bus.pop();
}
}
return result;
}
};