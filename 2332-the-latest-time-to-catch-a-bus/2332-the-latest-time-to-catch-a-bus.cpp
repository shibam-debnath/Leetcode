class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &p, int capacity)
    {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> bus, passenger;
        int result = 0;

        for (auto dep_time : buses)
        {
            bus.push(dep_time);
        }
        for (auto arr_time : p)
        {
            passenger.push(arr_time);
            // using un_map so that we can easily search later
            mp[arr_time]++;
        }

        while (!bus.empty())
        {
            int c = 0, last_passenger = 0;
            while (c < capacity && passenger.top() <= bus.top() && !passenger.empty())
            {
                last_passenger = passenger.top(); // store the arrival time of last passenger
                passenger.pop();

                // find if the arrival time -> last_passenger - 1 is available or not
                if (mp.find(last_passenger - 1) == mp.end())
                {
                    result = last_passenger - 1;
                }
                c++;
            }

            // suppose for this bus departure time is 10 and our last_passenger comes at 3
            // In this case our ans is 10 because we want the latest time to catch the bus
            if (last_passenger < bus.top() && c < capacity)
            {
                result = bus.top();
            }
            bus.pop();
        }
        return result;
    }
};