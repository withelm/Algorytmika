class Solution
{
private:
    long long int n, sum, index_max;

    int findMaxIndexElement(vector<int> &target)
    {
        return max_element(target.begin(), target.end()) - target.begin();
    }

public:
    bool isPossible(vector<int> &target)
    {

        for (auto &x : target)
            sum += x;
        index_max = findMaxIndexElement(target);

        while (sum > 1 && target[index_max] > sum / 2)
        {
            sum -= target[index_max];
            if (sum <= 1)
                return sum != 0;
            target[index_max] = target[index_max] % sum;
            sum += target[index_max];
            index_max = findMaxIndexElement(target);
        }
        return sum == target.size();
    }
};