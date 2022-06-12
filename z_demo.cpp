// Shibam Debnath
// May 23,2022

// linked list
struct ListNode
{
    int val;
    ListNode *next;
};
// tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    // Main function goes here
    cout << "hello bruhh ! If you have come upto this ! please give a start to this repo 😢";
    return 0;
}

// Shibam Debnath
// May 27,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int n = words.size();
    int linelen = 9, dif = 0, sp_pos = 0, sp_each = 0, extra = 0;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        linelen = words[i].size();                        // start with first word
        while (j < n && linelen + (j - i + 1) < maxWidth) // j-i+1 == no of spaces req
        {
            linelen += words[j].size(); // keep adding untill len > max
            j++;
        }

        dif = maxWidth - linelen;
        sp_pos = j - i - 1;
        sp_each = dif / sp_pos;
        extra = dif % sp_pos;

        string s;
        // here we have two cases
        // if no of words is one
        // or it is the last word else rest
        int tot_word = j - i;
        if (tot_word == 1 || j == words.size())
        {
            // left justified
            s += words[j] + string(maxWidth - linelen - (tot_word - 1), ' ');
            ;
        }
        else
        {
            // not last line and have at least two words
        }
    }
}
int main()
{
    // Main function goes here
    return 0;
}