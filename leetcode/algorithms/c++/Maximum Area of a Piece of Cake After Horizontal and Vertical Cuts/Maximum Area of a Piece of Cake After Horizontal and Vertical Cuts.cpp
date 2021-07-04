class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());

        vector<long long int> nh;
        vector<long long int> nv;

        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            nh.push_back(horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            nv.push_back(verticalCuts[i] - verticalCuts[i - 1]);
        }
        sort(nh.begin(), nh.end());
        sort(nv.begin(), nv.end());
        return (nh.back() * nv.back()) % (1000000000 + 7);
    }
};