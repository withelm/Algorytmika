#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long long int tmp_x = x;
        long long int y= 0;
        while(tmp_x != 0) {
            y *= 10;
            y += tmp_x % 10;
            tmp_x /= 10;
        }
        return x == y;
        
    }
};

int main()
{
  
}