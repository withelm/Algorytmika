class Solution
{
private:
    vector<int> f;
    int find_s(int a)
    {
        if (f[a] == a)
            return a;
        return f[a] = find_s(f[a]);
    }
    void union_s(int a, int b)
    {
        f[find_s(a)] = find_s(b);
    }
    void full_union(int a)
    {
        for (int i = 2; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                union_s(i, a);
                union_s(a / i, a);
            }
        }
    }

public:
    int largestComponentSize(vector<int> &A)
    {
        for (int i = 0; i <= 100000; i++)
        {
            f.push_back(i);
        }

        for (auto &a : A)
        {
            full_union(a);
        }

        map<int, int> counter;
        int result = 0;
        for (auto &x : A)
        {
            ++counter[find_s(x)];
            result = max(result, counter[find_s(x)]);
        }
        return result;
    }
};