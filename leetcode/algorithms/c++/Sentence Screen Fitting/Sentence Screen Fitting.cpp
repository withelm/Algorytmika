class Solution
{
public:
    int wordsTyping(vector<string> &s, int rows, int cols)
    {
        int curr_row = 0;
        int curr_column = 0;
        int curr_index = 0;
        int r = 0;
        int n = s.size();

        for (auto &x : s)
            if (x.size() > cols)
                return 0;

        vector<int> prefix(n, 0);
        prefix[0] = s[0].size();
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + s[i].size() + 1;
        }

        while (true)
        {

            int allSize = prefix[n - 1] + 1;
            r += (cols - curr_column) / allSize;
            curr_column += ((cols - curr_column) / allSize) * allSize;
            // cout << curr_column << " " << curr_row << " " << r << endl;

            for (int i = 0; i < n; i++)
            {
                if (curr_column + s[i].size() <= cols)
                {
                    curr_column += s[i].size() + 1;
                }
                else
                {
                    ++curr_row;
                    if (curr_row >= rows)
                        break;
                    curr_column = s[i].size() + 1;
                }
                //   cout << curr_column << " " << curr_row << endl;
            }
            if (curr_row >= rows)
                break;
            ++r;
        }
        return r;
    }
};