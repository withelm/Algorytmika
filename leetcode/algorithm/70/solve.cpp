#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int tab[n + 1];
        tab[0] = 1;
        tab[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            tab[i] = tab[i-1] + tab[i-2];
        }
        return tab[n];
    }
};

int main()
{
 
}