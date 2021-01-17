class TwoSum
{
public:
    /** Initialize your data structure here. */
    vector<int> k;
    bool isNew;
    TwoSum()
    {
        k.clear();
        isNew = false;
    }

    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        k.push_back(number);
        isNew = true;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        if (isNew)
        {
            isNew = false;
            sort(k.begin(), k.end());
        }
        int begin = 0;
        int end = k.size() - 1;
        while (begin < end)
        {
            if (k[begin] + k[end] > value)
            {
                --end;
            }
            else if (k[begin] + k[end] < value)
            {
                ++begin;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */