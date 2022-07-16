// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define Imposter                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);


class Trie
{
public:
    Trie *trieNodes[26];
    bool End = false;
};

class WordDictionary
{
public:

    Trie *root = new Trie();

    WordDictionary()
    {
    }

    void addWord(string word)
    {
        Imposter
        Trie *node = root;
        for (char c : word)
        {
            if (node->trieNodes[c - 'a'] == NULL)
            {
                node->trieNodes[c - 'a'] = new Trie();
            }
            node = node->trieNodes[c - 'a'];
        }
        node->End = true;
    }


    bool solve(string word, Trie *node)
    {
        Imposter 
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                // we need to check for a to z in this case
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (node->trieNodes[c - 'a'] && solve(word.substr(i + 1), node->trieNodes[c - 'a']))
                        return true;
                }
                return false;
            }
            else
            {
                if (node->trieNodes[word[i] - 'a'] == NULL)
                    return false;
                node = node->trieNodes[word[i] - 'a'];
            }
        }
        if (node->End)
            return true;
        return false;
    }
    bool search(string word)
    {
        Imposter
        Trie *node = root;
        return solve(word, node);
    }
};

int main()
{
    // Main function goes here
    return 0;
}