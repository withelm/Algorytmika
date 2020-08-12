#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int tmp_result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp_result = 0;
                while( i < nums.size() && nums[i] == 1) {
                    ++tmp_result;
                    ++i;
                }
                result = max(result, tmp_result);
            }
        }
        return  max(result, tmp_result);
    }
};

int main()
{
    
}