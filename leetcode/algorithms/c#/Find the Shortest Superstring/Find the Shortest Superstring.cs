public class Solution
{
    private List<List<int>> over;

    private int n;

    private List<string> words;

    private int LIMIT;

    private List<List<int>> dp;

    private List<List<int>> parent;

    public string ShortestSuperstring(string[] _words)
    {
        words = _words.ToList();
        n = words.Count();

        LIMIT = 1 << n;

        initOver();

        dp = new List<List<int>>();
        parent = new List<List<int>>();
        for (int i = 0; i < LIMIT; i++)
        {
            var tmp = new List<int>();
            for (int j = 0; j < n; j++) tmp.Add(0);
            dp.Add (tmp);

            var tmp2 = new List<int>();
            for (int j = 0; j < n; j++) tmp2.Add(-1);
            parent.Add (tmp2);
        }

        for (int mask = 0; mask < LIMIT; mask++)
        {
            for (int bit = 0; bit < n; bit++)
            {
                if ((mask >> bit & 1) > 0)
                {
                    int pmask = mask ^ (1 << bit);
                    if (pmask == 0) continue;
                    for (int i = 0; i < n; i++)
                    {
                        if (((pmask >> i) & 1) > 0)
                        {
                            int val = dp[pmask][i] + over[i][bit];
                            if (val > dp[mask][bit])
                            {
                                dp[mask][bit] = val;
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }

        List<int> perm = new List<int>();
        List<bool> vis = new List<bool>();

        for (int i = 0; i < n; i++) vis.Add(false);

        int mask2 = LIMIT - 1;

        int p = 0;
        for (int j = 0; j < n; j++)
        {
            if (dp[(1 << n) - 1][j] > dp[(1 << n) - 1][p])
            {
                p = j;
            }
        }

        while (p != -1)
        {
            perm.Add (p);
            vis[p] = true;
            int p2 = parent[mask2][p];
            mask2 = mask2 ^ (1 << p);
            p = p2;
        }

        for (int i = 0; i < perm.Count() / 2; i++)
        {
            int v = perm[i];
            perm[i] = perm[perm.Count() - 1 - i];
            perm[perm.Count() - 1 - i] = v;
        }

        for (int i = 0; i < n; i++) if (!vis[i]) perm.Add(i);

        string result = words[perm[0]];

        for (int i = 1; i < n; i++)
        {
            int overlap = over[perm[i - 1]][perm[i]];
            result += words[perm[i]].Substring(overlap);
        }

        return result;
    }

    private void initOver()
    {
        over = new List<List<int>>();
        for (int i = 0; i < n; i++)
        {
            var tmp = new List<int>();
            for (int j = 0; j < n; j++) tmp.Add(0);
            over.Add (tmp);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                for (
                    int k = Math.Min(words[i].Count(), words[j].Count());
                    k > 0;
                    k--
                )
                {
                    if (words[i].EndsWith(words[j].Substring(0, k)))
                    {
                        over[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
}
