class Solution
{
private:
    int n;

    int find_index(vector<int> &arr, int max_el, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == max_el)
                return i;
        }
        return -1;
    }
    void flip(vector<int> &arr, int k)
    {

        reverse(arr.begin(), arr.begin() + k);
    }

public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> r;

        n = arr.size();
        while (n > 0)
        {
            int max_el = *max_element(arr.begin(), arr.begin() + n);

            int index = find_index(arr, max_el, n);
            r.push_back(index + 1);
            flip(arr, index + 1);
            r.push_back(n);
            flip(arr, n);
            --n;
        }

        return r;
    }
};