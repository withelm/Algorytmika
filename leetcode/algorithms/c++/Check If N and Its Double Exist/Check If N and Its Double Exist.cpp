class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++)
        {
            for (vector<int>::iterator j = arr.begin(); j != arr.end(); j++)
            {
                if (2 * (*i) == *j && i != j)
                    return true;
            }
        }

        return false;
    }
};