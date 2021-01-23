class KthLargest
{
private:
    vector<int> t;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        t = nums;
        sort(t.begin(), t.end());
    }

    int add(int val)
    {
        int index = 0;
        while (index < t.size() && val > t[index])
            ++index;
        t.insert(t.begin() + index, val);

        return t[t.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */