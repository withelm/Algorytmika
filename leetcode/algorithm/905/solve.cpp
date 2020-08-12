#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        for(vector<int>::iterator it = A.begin(); it != A.end(); it++) {
            if (*it % 2 == 0) {
                result.push_back(*it);
            }
        }
        for(vector<int>::iterator it = A.begin(); it != A.end(); it++) {
            if (*it % 2 == 1) {
                result.push_back(*it);
            }
        }
        return result;
    }
};

int main()
{
    
}