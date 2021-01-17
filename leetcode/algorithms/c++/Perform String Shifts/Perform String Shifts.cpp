class Solution
{

private:
    int n;
    string rol(string &s, int r)
    {
        string result = "";

        for (int i = 0; i < n; i++)
        {
            result += s[(i + r) % n];
        }
        return result;
    }

public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int finally_rol = 0;
        n = s.size();
        for (auto &i : shift)
        {
            if (i[0] == 0)
                finally_rol += i[1];
            else
                finally_rol += -i[1];
        }

        while (finally_rol < 0)
            finally_rol += n;
        finally_rol %= n;

        return rol(s, finally_rol);
        ;
    }
};