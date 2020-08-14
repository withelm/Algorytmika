#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       vector<int> tmp(nums.size() + 1);
       
       for(int i = 1; i <= nums.size(); i++) {
           tmp[i] = 0;
       }
       for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
           tmp[*it] = 1;
       }
       
       vector<int> result;
       for(int i = 1; i <= nums.size(); i++) {
           if (tmp[i] == 0)
            result.push_back(i);
       }
       return result;
        
    }
};

int main()
{
    
}