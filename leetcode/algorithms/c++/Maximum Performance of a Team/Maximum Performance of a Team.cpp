class Person
{
public:
    int speed;
    int efficiency;
};

class Solution
{
private:
    int MOD = 1e9 + 7;
    vector<Person> cand;
    priority_queue<int, std::vector<int>, std::greater<int>> qspeed;

public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        for (int i = 0; i < n; i++)
        {
            Person p;
            p.speed = speed[i];
            p.efficiency = efficiency[i];
            cand.push_back(p);
        }
        sort(cand.begin(), cand.end(), [](const Person &x, const Person &y)
             { return x.efficiency > y.efficiency; });
        long long int rspeed = 0;
        long long int eff = 0;
        for (auto &item : cand)
        {
            if (qspeed.size() > k - 1)
            {
                rspeed -= qspeed.top();
                qspeed.pop();
            }
            qspeed.push(item.speed);
            rspeed += item.speed;
            eff = max(eff, rspeed * item.efficiency);
        }
        return eff % MOD;
    }
};