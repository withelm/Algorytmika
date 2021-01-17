class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int index = 0;
        int n = arr.size();
        while (arr[index] < arr[index + 1])
            ++index;
        return index;
    }
};