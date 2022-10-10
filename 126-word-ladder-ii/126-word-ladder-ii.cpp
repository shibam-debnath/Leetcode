class Solution
{
    public:
    vector<vector<string>> ans;
    unordered_map<string, unordered_set < string>> graph;
    unordered_map<string, int> visited;

    vector<vector < string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wl(begin(wordList), end(wordList));
        if (!wl.count(endWord) || wl.empty()) return ans;

        visited[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < cur.size(); i++)
            {
                string temp = cur;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
       	            // new char added
                    temp[i] = ch;
                    if (temp == cur) continue;
       	            
                    // check if this string is present or not
                    if (wl.count(temp))
                    {
       	                // if not visited directly add to directed graph
                        if (!visited.count(temp))
                        {
                            visited[temp] = 1 + visited[cur];
                            graph[temp].insert(cur);	// NOTE: beginWord < - endWord is the direction
                            q.push(temp);
                        }

       	                // if visited but it is in the immediate next level then also add since we want all possible paths 
                        else if (visited[temp] == 1 + visited[cur])
                            graph[temp].insert(cur);
                    }
                }
            }
        }

        all_paths_dfs(endWord, beginWord);
        return ans;

    }

    vector<string> path;
    void all_paths_dfs(string &s, string &e)
    {
        if (s == e)
        {
            path.emplace_back(s);
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            path.pop_back();
            return;
        }

        path.emplace_back(s);
        cout << s << " ";
        for (auto ch: graph[s]) all_paths_dfs(ch, e);
        path.pop_back();
    }
};