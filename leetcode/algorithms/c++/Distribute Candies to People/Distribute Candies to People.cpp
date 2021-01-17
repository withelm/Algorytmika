class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int acc = 1;
        int index = 0;
        vector<int> result(num_people);
        while (acc <= candies)
        {
            result[index % num_people] += acc;
            candies -= acc;
            ++acc;
            ++index;
        }
        result[index % num_people] += candies;
        return result;
    }
};