bool cmp(vector<int> &x, vector<int> &y)
{
    return x[2] < y[2];
}

class Solution
{
private:
    map<int, int> base;
    vector<int> reBase;

    int MX = 1 << 15;
    int MX2 = MX * 2;
    int wynik = 0;

    vector<int> W;
    vector<int> w;

    void init(vector<vector<int>> &buildings)
    {
        W.resize(MX2 * 2);
        w.resize(MX2 * 2);
        reBase.resize(MX2 * 2);
        for (int i = 0; i < MX2; i++)
            W[i] = w[i];

        int tmp = 1;
        for (auto &x : buildings)
        {
            base[x[0]] = 0;
            base[x[1]] = 0;
            base[x[1] - 1] = 0;
        }
        for (auto &x : base)
        {
            x.second = tmp;
            reBase[tmp] = x.second;
            ++tmp;
        }
        for (auto &x : buildings)
        {
            x[0] = base[x[0]];
            x[1] = base[x[1] - 1];
        }
    }

    void insert(int x, int a, int b, int p, int k, int v)
    {
        bool baza = false;
        if (a == p && b == k)
        {
            //cout << v << endl;
            W[v] = x;
            w[v] = x;
            baza = true;
        }
        if (w[v] != 0)
        {
            W[2 * v] = w[v];
            w[2 * v] = w[v];
            W[2 * v + 1] = w[v];
            w[2 * v + 1] = w[v];
            w[v] = 0;
        }

        if (!baza)
        {
            int sr = (p + k) / 2;
            if (b <= sr)
                insert(x, a, b, p, sr, 2 * v);
            else if (a > sr)
                insert(x, a, b, sr + 1, k, 2 * v + 1);
            else
            {
                insert(x, a, sr, p, sr, 2 * v);
                insert(x, sr + 1, b, sr + 1, k, 2 * v + 1);
            }
            W[v] = max(W[2 * v], W[2 * v + 1]);
        }
    }

    void query(int a, int b, int p, int k, int v)
    {
        bool baza = false;
        if (a == p && b == k)
        {
            //cout << v << endl;
            wynik = max(wynik, W[v]);
            baza = true;
        }
        if (w[v] != 0)
        {
            W[2 * v] = W[v];
            w[2 * v] = W[v];
            W[2 * v + 1] = W[v];
            w[2 * v + 1] = W[v];
            w[v] = 0;
        }

        if (!baza)
        {
            int sr = (p + k) / 2;
            if (b <= sr)
                query(a, b, p, sr, 2 * v);
            else if (a > sr)
                query(a, b, sr + 1, k, 2 * v + 1);
            else
            {
                query(a, sr, p, sr, 2 * v);
                query(sr + 1, b, sr + 1, k, 2 * v + 1);
            }
            W[v] = max(W[2 * v], W[2 * v + 1]);
        }
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        if (buildings.size() == 0)
            return {};
        init(buildings);
        sort(buildings.begin(), buildings.end(), cmp);
        int min_v = buildings[0][0];
        int max_v = buildings[0][1];
        for (auto &x : buildings)
        {
            min_v = min(x[0], min_v);
            max_v = max(x[1], max_v);

            insert(x[2], x[0] + MX, x[1] + MX, MX, MX2 - 1, 1);
        }
        vector<vector<int>> vals;
        for (auto i : base)
        {
            wynik = 0;
            query(i.second + MX, i.second + MX, MX, MX2 - 1, 1);
            if (vals.size() == 0)
            {
                vals.push_back({i.first, wynik});
            }
            else if (vals.back()[1] != wynik)
            {
                vals.push_back({i.first, wynik});
            }
        }
        return vals;
    }
};