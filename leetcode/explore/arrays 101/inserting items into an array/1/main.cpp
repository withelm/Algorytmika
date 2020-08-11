#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp;
        for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
            tmp.push_back(*it);
        }
        int index = 0;
        int index2 = 0;
        int len = arr.size();
        while(index < len) {
            if (tmp[index2] != 0) {
                arr[index] = tmp[index2];
                ++index;
                ++index2;
            } else {
                arr[index] = 0;
                if (index + 1 < len)
                    arr[index + 1] = 0;
                index += 2;
                ++index2;
            }
        }
    }
};

int main()
{

}