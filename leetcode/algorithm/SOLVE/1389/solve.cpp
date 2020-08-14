#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            result[index[i]] = nums[i];
        }
        return result;
    }
};

int main()
{
    
}