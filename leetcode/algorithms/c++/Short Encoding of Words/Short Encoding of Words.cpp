class Point
{
public:
    char val;
    map<char, Point *> child;
    Point()
    {
    }
};
class Solution
{
private:
    Point *root;
    void add(string &x)
    {
        reverse(x.begin(), x.end());
        Point *t = root;
        for (auto &i : x)
        {
            if (t->child[i] == NULL)
                t->child[i] = new Point();
            t = t->child[i];
        }
    }

    int dfs(Point *x, int deep)
    {
        if (x == NULL)
            return 0;
        if (x->child.size() == 0)
            return deep + 1;
        int r = 0;
        for (auto &i : x->child)
            r += dfs(i.second, deep + 1);
        return r;
    }

public:
    int minimumLengthEncoding(vector<string> &words)
    {
        root = new Point();
        for (auto &x : words)
            add(x);
        return dfs(root, 0);
    }
};