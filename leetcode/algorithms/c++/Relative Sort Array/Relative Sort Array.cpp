

map<int, int> base;

class Solution
{
private:
    static bool cmp(int a, int b)
    {
        if (base[a] == base[b])
            return a < b;
        return base[a] < base[b];
    }

public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {

        int index = 0;
        for (auto &x : arr1)
            base[x] = 1000 + 1000;
        for (auto &x : arr2)
            base[x] = index++;
        sort(arr1.begin(), arr1.end(), cmp);
        //[](const int & a, const int & b) -> bool
        /*{ 
            if (Base::base[a] == Base::base[b])
                return a < b;
            return Base::base[a] < Base::base[b];
        });*/
        return arr1;
    }
};