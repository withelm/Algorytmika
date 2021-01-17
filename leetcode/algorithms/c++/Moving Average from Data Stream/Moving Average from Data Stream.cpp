class MovingAverage
{
private:
    vector<int> v;
    int sum;
    int index_begin;
    int index_end;
    int n;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        n = size;
        index_begin = 0;
        index_end = 0;
        sum = 0;
        v.clear();
    }

    double next(int val)
    {
        v.push_back(val);
        ++index_end;
        sum += val;
        if (index_end - index_begin > n)
        {
            sum -= v[index_begin];
            ++index_begin;
        }
        int div = index_end - index_begin;
        return (double)sum / (double)div;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */