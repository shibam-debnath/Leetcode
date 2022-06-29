class Solution
{

    private:
        struct TrieNode
        {
            bool End = false;
            TrieNode *child[26] = { NULL
            };
        };

    TrieNode *trie = new TrieNode();

    public:

        void insert(string word)
        {
            TrieNode *temp = trie;
            for (auto &c: word)
            {
                int pos = c - 'a';
                if (!temp->child[pos])
                {
                    temp->child[pos] = new TrieNode();
                }
                temp = temp->child[pos];
            }
            temp->End = true;
        }

    string longestWord(vector<string> &words)
    {

        string ans;
       	// first insert all strings
       	// sabke last mein End pointer is true
        for (auto &s: words)
        {
            insert(s);
        }

       	// now find the longest word
        TrieNode *temp;

       	//traverse each word and check if it satisfies our condition or not
        for (auto &word: words)
        {
            if(word.size() < ans.size()) continue;
            temp = trie;
           	// traverse each char 
            for (auto &c: word)
            {
                int pos = c - 'a';
               	//go to it's just next child and check the End flag is true or not
                temp = temp->child[pos];
               	// check it is true or not
                if (temp->End==false) break;
            }

           	// this word has all end->true (except last)
           	// handle equal string (lexicogra..) alag se
            if (temp->End == true && (word.size() > ans.size() || (word.size() == ans.size() && word < ans)))
            {
                ans = word;
            }
        }

        return ans;
    }
};