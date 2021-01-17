class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        vector<int> lastV;
        vector<int> beginV;
        int n = arr.size();

        int index = n - 1;
        int last = arr[index];

        while (index >= 0 && last >= arr[index])
        {
            lastV.push_back(arr[index]);
            last = arr[index];
            --index;
        }
        index = 0;
        last = arr[0];
        while (index < n && last <= arr[index])
        {
            beginV.push_back(arr[index]);
            last = arr[index];
            ++index;
        }
        reverse(lastV.begin(), lastV.end());

        if (n == lastV.size())
            return 0;
        //if (lastV.size() == 1) return n - 1;

        int result = n;
        last = arr[0];
        for (int i = 0; i < n; i++)
        {
            //cout << "HI!" << endl;
            if (last <= arr[i])
            {
                last = arr[i];

                auto first = lower_bound(lastV.begin(), lastV.end(), arr[i]);
                int index_first = first - lastV.begin();
                //cout << n << " " << lastV.size() << " " << i << " " << index_first << endl;
                int tmp = n - lastV.size() - i - 1 + index_first;
                result = min(result, tmp);
            }
            else
            {
                break;
            }
        }
        if (n - lastV.size() < result)
            return n - lastV.size();
        return result;
    }
};