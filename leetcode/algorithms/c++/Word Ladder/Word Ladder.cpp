class Solution
{
private:
    map<string, int> base;
    vector<string> rev_base;
    vector<vector<int>> g;
    vector<string> wordList;

    vector<int> len;
    vector<bool> vis;
    int INF = 1e9;

    int n;

    bool check(string &x, string &y)
    {
        int diff = 0;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] != y[i])
            {
                if (diff > 0)
                    return false;
                ++diff;
            }
        }
        return true;
    }

    vector<string> find(string &x)
    {
        if (base.find(x) != base.end())
            return {x};
        vector<string> r;
        for (auto &i : wordList)
            if (check(i, x))
                r.push_back(i);
        return r;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &w)
    {
        if (beginWord == endWord)
            return 0;
        wordList = w;
        n = wordList.size();
        cout << "MAP\r\n";
        for (int i = 0; i < n; i++)
        {
            base[wordList[i]] = i;

            cout << wordList[i] << " " << i << endl;
            rev_base.push_back(wordList[i]);
        }
        g.resize(n);
        len.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++)
            len[i] = INF;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        cout << "GRAPH\r\n";
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            for (auto &x : g[i])
                cout << x << " ";
            cout << endl;
        }

        int r = 0;
        if (base.find(beginWord) == base.end())
            ++r;
        if (base.find(endWord) == base.end())
            ++r;

        auto startList = find(beginWord);

        vector<int> qu;

        for (auto &x : startList)
        {
            int tmp = base[x];
            len[tmp] = 0;
            vis[tmp] = true;
            qu.push_back(tmp);
        }
        cout << "QUEUE" << endl;
        while (qu.size() > 0)
        {
            vector<int> tmp;
            for (auto &i : qu)
            {
                cout << i << " ";
                for (auto &j : g[i])
                {
                    if (!vis[j])
                    {
                        len[j] = len[i] + 1;
                        vis[j] = true;
                        tmp.push_back(j);
                    }
                }
            }
            cout << endl;
            qu = tmp;
        }

        if (base.find(endWord) == base.end())
            return 0;
        if (vis[base[endWord]])
            return len[base[endWord]] + r + 1;
        return 0;
    }
};