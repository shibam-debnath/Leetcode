class Solution
{
    public:
        bool isVowel(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }

    string reverseVowels(string s)
    {

        vector<char> v;
        vector<int> m;

        for (int i = 0; i < s.size(); ++i)
        {
            if (isalpha(s[i]))
            {
                if (isVowel(s[i]))
                {
                   	// cout << i << " " << s[i] << endl;
                    v.push_back(s[i]);
                    m.push_back(i);
                }
            }
        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); ++i)
        {
            s[m[i]] = v[i];
        }

        return s;
    }
};