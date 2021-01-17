class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string result(s.size(), ' ');
        int index = 0;
        for (auto &indice : indices)
        {
            result[indice] = s[index++];
        }
        return result;
    }
};