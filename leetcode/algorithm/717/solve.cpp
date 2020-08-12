#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        bool status = false;
        for(int i = 0; i < len;) {
            if (bits[i] == 1) {
                i += 2;
                status = false;
            } else {
                status = true;
                ++i;
            }
        }
        return status;
    }
};

int main()
{
  
}