class Solution
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    int connectSticks(vector<int> &sticks)
    {
        int result = 0;

        for (auto &x : sticks)
            pq.push(x);
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            result += a + b;
            pq.push(a + b);
        }

        return result;
    }
};