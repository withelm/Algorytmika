class Solution
{
public:
    int sumOfDigits(vector<int> &A)
    {
        int min_el = *min_element(A.begin(), A.end());

        int suma = 0;
        while (min_el > 0)
        {
            suma += min_el % 10;
            min_el /= 10;
        }
        return ((suma + 1) % 2);
    }
};