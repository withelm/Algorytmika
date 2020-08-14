#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digs;
        bool isFirstSix = false;
        while(num > 0) {
            
            digs.push_back(num % 10);
            
            num /= 10;
        }
        reverse(digs.begin(), digs.end());

        int result = 0;
        int ten = 10;
        for(auto &dig : digs) {
            if (!isFirstSix && dig == 6) {
                result = result * ten + 9;
                isFirstSix = true;
            } else {
                result = result * ten + dig;
            }
        }
        return result;
    }
};

int main()
{
   
}