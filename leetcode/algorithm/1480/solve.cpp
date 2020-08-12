#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tmp = 0;
        vector<int> result;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            tmp += *it;
            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{

}