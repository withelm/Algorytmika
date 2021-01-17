class Solution
{
private:
    int gdc(int a, int b)
    {
        if (b != 0)
            return gdc(b, a % b);

        return a;
    }

public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        set<vector<int>> b;
        int n = coordinates.size();
        for (int i = 1; i < n; i++)
        {
            //for(int j = 0; j < n; j++) {
            //  if (i == j) continue;
            int a1 = coordinates[i - 1][0] - coordinates[i][0];
            int a2 = coordinates[i - 1][1] - coordinates[i][1];
            int c = gdc(a1, a2);
            a1 /= c;
            a2 /= c;
            // cout << a1 << " " << a2 << endl;
            b.insert({a1, a2});
        }
        return b.size() == 1;
    }
};