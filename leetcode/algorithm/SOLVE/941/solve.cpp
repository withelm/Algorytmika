#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 1) return false;
        int last = *(A.begin());
        bool isUp = true;
        bool isExistUp = false;
        bool isExistDown = false;
        for(vector<int>::iterator it = A.begin() + 1; it != A.end(); it++ ) {
            
            if (last == *it) return false;
            if (last < *it) {
                if (!isUp) return false;
                isExistUp = true;
            }
            if (last > *it) {
                isUp = false;
                isExistDown = true;
            }

            last = *it;
        }
        
        return isExistUp && isExistDown;
    }
};

int main()
{
   
}