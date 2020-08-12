#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        
        int sum = 1;
        vector<int> result;
        
        for(int i = 0; i < digits.size(); i++) {
            sum += digits[i];
            result.push_back(sum % 10);
            sum /= 10;
        }
        if (sum != 0)
            result.push_back(sum);
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    
}