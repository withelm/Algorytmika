#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (*it != 0) {
                tmp.push_back(*it);
            }
        }
        for(int i = 0; i < tmp.size(); i++) {
            nums[i] = tmp[i];
        }
        for(int i = tmp.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

  
};

int main()
{
   
}