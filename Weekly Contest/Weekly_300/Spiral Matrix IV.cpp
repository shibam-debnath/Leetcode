// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        int x = 0, y = 0, di = 0;

        for (int i = 0; i < m * n; i++)
        {
            seen[x][y] = true;
            res[x][y] = head->val;

            int newX = x + dr[di];
            int newY = y + dc[di];

            if (0 <= newX && newX < m && 0 <= newY && newY < n && !seen[newX][newY])
            {
                x = newX;
                y = newY;
            }
            else
            {
                di = (di + 1) % 4;
                x += dr[di];
                y += dc[di];
            }
        }
        return res;

       

        return res;
    }
};

int main()
{
    // Main function goes here
    return 0;
}
