#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    
    int val[255];
    
    int numJewelsInStones(string J, string S) {
        for(int i = 0; i < 255; i++)
            val[i] = 0;
        
        for(int i = 0; i < J.size(); i++) 
            val[J[i]] = 1;
        
        int result = 0;
        for(int i = 0; i < S.size(); i++) {
            result += val[S[i]];
        }
        return result;
    }
};

int main()
{
    
}