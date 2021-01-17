class Trie
{
public:
    Trie *node[2];
    int val;
};

class Solution
{
private:
    vector<int> toBin(int k)
    {
        vector<int> r;
        while (k > 0)
        {
            r.push_back(k % 2);
            k /= 2;
        }
        reverse(r.begin(), r.end());
        return r;
    }
    vector<int> toBin(int k, int n)
    {
        vector<int> r(n, 0);
        int index = 0;
        while (k > 0)
        {
            r[(n - index++) - 1] = k % 2;
            k /= 2;
        }
        // while(index < n)
        //      r[index++] = 0;

        return r;
    }
    Trie *root;
    void add(vector<int> &k)
    {
        Trie *p = root;
        for (auto &i : k)
        {
            if (p->node[i] == NULL)
            {
                p->node[i] = new Trie();
            }
            p = p->node[i];
        }
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        int r = 0;
        int n = nums.size();

        int max_v = nums[0];
        for (int i = 1; i < n; i++)
            max_v = max(nums[i], max_v);

        auto max_bin = toBin(max_v);
        int m = max_bin.size();
        root = new Trie();
        for (auto &i : nums)
        {
            auto bin = toBin(i, m);

            add(bin);
        }

        for (auto &i : nums)
        {
            Trie *c = root;
            int v = 0;
            auto b = toBin(i, m);
            for (int j = 0; j < m; j++)
            {
                v *= 2;

                if (c->node[(b[j] + 1) % 2] != NULL)
                {
                    v += (b[j] + 1) % 2;
                    c = c->node[(b[j] + 1) % 2];
                }
                else
                {
                    v += b[j];
                    c = c->node[b[j]];
                }
            }
            r = max(r, v ^ i);
        }

        return r;
    }
};