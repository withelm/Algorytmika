class NumArray
{
private:
    vector<int> t;
    int n;
    vector<int> nums;

    int magic(int x)
    {
        return ((x ^ (x - 1)) + 1) / 2;
    }

public:
    NumArray(vector<int> &_nums)
    {
        n = 1e6;
        nums = _nums;
        t.resize(n);
        for (int i = 0; i < nums.size(); i++)
        {
            insert(i + 1, nums[i]);
        }
    }

    void update(int index, int val)
    {
        insert(index + 1, -nums[index]);
        nums[index] = val;
        insert(index + 1, nums[index]);
        //cout << "update " << index << " " << val << endl;
    }

    void insert(int index, int val)
    {
        while (index < n)
        {
            t[index] += val;
            index += magic(index);
        }
    }

    int sumRange(int left, int right)
    {
        // cout << "sum " << sum(right + 1) << " " << sum(left) << endl;
        return sum(right + 1) - sum(left);
    }
    int sum(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += t[x];
            x -= magic(x);
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */