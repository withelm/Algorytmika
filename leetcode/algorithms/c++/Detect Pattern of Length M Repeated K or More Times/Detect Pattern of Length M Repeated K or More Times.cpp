class Solution
{
private:
    bool check(vector<int> &arr, int i, int m, int k)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            tmp.push_back(arr[j + i]);
        }
        int index = 0;
        for (int j = i; j < (m * k) + i; j++)
        {
            //  cout << "> " << j << " " << index << endl;
            if (arr[j] != tmp[index])
            {
                return false;
            }
            index = (index + 1) % m;
        }
        return true;
    }

public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int n = arr.size();
        if (n < m * k)
            return false;
        for (int i = 0; i <= n - (m * k); i++)
        {
            //  cout << i << " " << m << " " << k << endl;
            if (check(arr, i, m, k))
                return true;
        }
        return false;
    }
};