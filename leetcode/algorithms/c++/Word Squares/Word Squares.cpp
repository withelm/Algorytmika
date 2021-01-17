class Solution
{
private:
    int n, m;
    vector<vector<string>> r;
    vector<bool> vis;
    vector<string> _words;
    map<string, vector<string>> base;

    void dfs(vector<string> &matrix, string word, int index)
    {
        addWord(matrix, word, index);
        ++index;
        if (index == m)
        {
            r.push_back(matrix);
            return;
        }
        auto finder = matrix[index].substr(0, index);
        for (auto &x : base[finder])
        {
            dfs(matrix, x, index);
        }
    }

    void addWord(vector<string> &matrix, string &word, int index)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][index] = word[i];
            matrix[index][i] = word[i];
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        _words = words;
        n = words.size();
        m = words[0].size();
        vector<string> matrix(m, string(m, 0));

        for (int i = 0; i < n; i++)
        {
            string tmp = "";
            for (int j = 0; j < m; j++)
            {
                tmp += words[i][j];
                base[tmp].push_back(words[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {

            dfs(matrix, words[i], 0);
        }

        return r;
    }
};