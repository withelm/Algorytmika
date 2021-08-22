class Solution {
private:
    map<int, int> mem;
    int f(int x)
    {
        if (x != mem[x])
            return mem[x] = f(mem[x]);
        return x;
    }
    void u(int x, int y)
    {
        mem[f(x)] =mem[f(y)];
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n != edges.size() + 1)
            return false;
        
        for(int i = 0; i < n; i++)
            mem[i] = i;
        
        for(auto &edge : edges)
            u(edge[0], edge[1]);
        
        set<int> tmp;
        for(int i = 0; i < n; i++)
            tmp.insert(f(i));
        return tmp.size() == 1;
    }
};