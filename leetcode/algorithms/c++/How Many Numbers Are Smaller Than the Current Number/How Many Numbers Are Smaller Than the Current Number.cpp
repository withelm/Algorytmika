
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        {
            int counter = 0;
            for (vector<int>::iterator j = nums.begin(); j != nums.end(); j++)
            {
                counter += i != j && *j < *i;
            }
            result.push_back(counter);
        }
        return result;
    }
};