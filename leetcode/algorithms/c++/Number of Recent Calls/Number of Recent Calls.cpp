class RecentCounter
{
private:
    queue<int> base;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        base.push(t);
        while (base.front() < t - 3000)
            base.pop();
        return base.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */