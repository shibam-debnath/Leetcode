// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Trie
{
private:
    struct TrieNode
    {
        // an array of pointers to other TrieNode instances, with size set to 26,
        //  since the specs clearly mention only lowercase letters;
        TrieNode *child[26] = {NULL};
        // boolean flag to mark a node as matching the last character of a given word
        bool End = false;
    };

    // initialization   
    TrieNode *trie = new TrieNode();

public:
    Trie()
    {
        // constructor
        cout << "Hurrah !";
    }

    void insert(string word)
    {
        // take a copy of trie
        TrieNode *temp = trie;
        // traverse each char in word
        for (auto &c : word)
        {
            int pos = c - 'a';
            // check if already present or not
            if (!temp->child[pos])
            {
                // if we don't have this char in trie then insert
                temp->child[pos] = new TrieNode();
            }
            // update temp
            temp = temp->child[pos];
        }
        // finally flag the last char as true i.e it is the end
        temp->End = true;
    }

    bool search(string word)
    {
        // take a copy of trie
        TrieNode *temp = trie;

        // traverse each char in word
        for (auto &c : word)
        {
            int pos = c - 'a';

            // check if already present or not
            if (!temp->child[pos])
            {
                return false;
            }
            // update temp
            temp = temp->child[pos];
        }
        // we are at the end of the word
        if (temp->End == true)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = trie;

        for (auto &c : prefix)
        {
            int pos = c - 'a';
            if (!temp->child[pos])
                return false;
            // else
            temp = temp->child[pos];
        }
        // since prefix it shouldn't be the end there
        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}