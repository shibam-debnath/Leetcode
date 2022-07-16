// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool replaceable(string &s, unordered_set<string> &mp)
    {
        string t = "";
        for (auto c : s)
        {
            t.push_back(c);
            if (mp.find(t) != mp.end())
            {
                s = t;
                return true;
            }
        }
        return false;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> mp;
        // insert all to hash map
        for (auto &word : dictionary)
        {
            mp.insert(word);
        }
        // while traversing the sentence keep checking if the word is present or not in map
        bool flag = false;
        string s = "";
        string ans;
        for (int i = 0; i < sentence.size(); i++)
        {
            // Make the flag true whenever find a space or end of sentence
            if (i == s.length() or s[i] == ' ')
            {
                s = "";
                flag = true;
            }
            else if (s[i] != ' ')
            {
                s += s[i]; // Add current char to a temperory variable
            }

            if (mp.find(s) != mp.end() and flag)
            {
                ans += s[i];
                flag = false;
            }
            else if (flag and i != s.length())
            {
                ans += s[i]; // Add the current char to answer if there was no match
            }
        }
        return ans;
    }
};

int main()
{
    // Main function goes here
    return 0;
}

queue<int> q1;
queue<int> q2;
MyStack()
{
}

void push(int x)
{
    q1.push(x);
}

int pop()
{
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int ans = q1.front();
    q1.pop();

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    return ans;
}

int top()
{
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int ans = q1.front();
    q2.push(ans);

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    return ans;
}

bool empty()
{

    return q1.empty();
}