class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> rounds;
        int sum = 0;
        for (auto &x : ops)
        {
            if (x == "C")
            {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            if (x == "D")
            {
                rounds.push_back(rounds.back() * 2);
                sum += rounds.back();
                continue;
            }
            if (x == "+")
            {
                rounds.push_back(rounds.back() + rounds[rounds.size() - 2]);
                sum += rounds.back();
                continue;
            }
            rounds.push_back(stoi(x));
            sum += rounds.back();
        }
        return sum;
    }
};