#include <bits/stdc++.h>
using namespace std;

void search(char pat[], char txt[])
{
    // length of both char arrays
    int n = strlen(pat);
    int m = strlen(txt);

    int i, j;

    for (i = 0; i <= m - n; i++)
    {
        bool flag = true;
        for (j = 0; j < n; j++)
        {
            if (txt[i + j] != pat[j])
            {
                flag = false;
                break;
            }
        }

        if (j == n && flag == true)
        {
            cout << "Pos found at :" << i << endl;
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    // Function Call
    search(pat, txt);
    return 0;
}
