class Tree
{
private:
    vector<int> base;
    int SIZE = 1 << 18;
    int FULL_SIZE = SIZE << 1;

public:
    Tree(int n)
    {
        base.resize(FULL_SIZE);
    }

    int magic(int x)
    {
        return x & -x;
    }

    void insert(int x, long long int v)
    {
        while (x < FULL_SIZE)
        {
            base[x] = base[x] + v;
            x += magic(x);
        }
    }

    int sum(int x)
    {
        long long int res = 0;
        while (x > 0)
        {
            //cout << x << endl;
            res = res + base[x];
            x -= magic(x);
        }
        return res;
    }

    long long int query(int left, int right)
    {
        return sum(right) - sum(left - 1);
    }
};

class Solution
{
private:
    int MOD = 1e9 + 7;

public:
    int createSortedArray(vector<int> &instructions)
    {
        int r = 0;
        int max_el = *max_element(instructions.begin(), instructions.end());
        Tree *root = new Tree(max_el + 2);

        for (auto &x : instructions)
        {
            //cout << x << endl;
            r = (r + min(root->query(0, x - 1), root->query(x + 1, max_el + 1))) % MOD;

            root->insert(x, 1);
        }
        //	cout << r << endl;
        return r;
    }
};