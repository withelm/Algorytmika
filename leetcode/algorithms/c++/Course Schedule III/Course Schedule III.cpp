class Solution
{

public:
    int scheduleCourse(vector<vector<int>> &c)
    {

        sort(c.begin(), c.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        priority_queue<int, vector<int>, less<int>> q;
        int time = 0;
        for (int i = 0; i < c.size(); i++)
        {
            auto item = c[i];

            if (time + item[0] <= item[1])
            {
                q.push(item[0]);
                time += item[0];
            }
            else if (!q.empty() && q.top() > item[0])
            {
                time -= q.top();
                q.pop();
                --i;
            }
        }
        return q.size();
    }
};