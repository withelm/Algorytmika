#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int a = -21474836480LL;
        long long int b = -21474836480LL; 
        long long int c = -21474836480LL;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (*it > a && *it != b && *it != c) {
                c = b;
                b = a;
                a = *it;
                continue;
            }
            if (*it > b && *it != c && *it != a) {
                c = b;
                b = *it;
                continue;
            }
            if (*it > c && *it != a && *it != b) {
                c = *it;
                continue;
            }
        }
        if (c == -21474836480LL)
            return a;
        return c;
    }
};

int main()
{
   
}