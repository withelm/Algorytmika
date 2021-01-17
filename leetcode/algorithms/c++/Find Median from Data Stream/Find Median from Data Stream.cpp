class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> f;
    priority_queue<int, vector<int>, greater<int>> s;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        f.push(num);
        s.push(f.top());
        f.pop();
        if (f.size() < s.size())
        {
            f.push(s.top());
            s.pop();
        }
    }

    double findMedian()
    {
        if (f.size() > s.size())
            return f.top();
        return (f.top() + s.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */