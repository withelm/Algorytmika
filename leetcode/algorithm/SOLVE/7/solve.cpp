#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        long long int result = 0;
        while (x != 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }

        if (result > (1 << 31) - 1 || result  < -(((long long int)1) << 31))
            return 0;

        return result;
    }
};

int main()
{

}