class Solution
{
private:
    set<vector<int>> datas;
    vector<vector<int>> answer;
    void findCycle(vector<int> &cells, int N)
    {
        for (int i = 0; true; i++)
        {
            vector<int> tmp(cells.size());
            tmp[0] = 0;
            tmp[7] = 0;
            for (int i = 1; i < 7; i++)
            {
                if (cells[i - 1] == cells[i + 1])
                    tmp[i] = 1;
                else
                    tmp[i] = 0;
            }
            for (int i = 0; i < 8; i++)
            {
                cells[i] = tmp[i];
            }

            if (datas.find(tmp) != datas.end())
                return;

            datas.insert(tmp);
            answer.push_back(tmp);
        }
    }

public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        if (N == 0)
            return cells;
        datas.clear();
        answer.clear();
        findCycle(cells, N);
        return answer[(N - 1) % answer.size()];
    }
};