#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0;
        int v = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'R')
                ++v;
            if (s[i] == 'L')
                --v;
            if (v == 0)
                ++r;
        }
        return r;
    }
};

int main()
{
   
}