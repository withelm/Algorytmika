/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution
{

public:
    int findCelebrity(int n)
    {

        vector<int> c(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (c[j] == 0 && knows(j, i))
                {
                    c[j] = 1;
                }
            }
        }

        // for(auto &x : c) cout << x << endl;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == 0)
            {
                bool isOk = true;
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    if (knows(i, j) || !knows(j, i))
                        return -1;
                }
                return i;
            }
        }

        return -1;
    }
};