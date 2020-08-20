#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), 
            [](auto x, auto y) {
                if (x[1] == y[1])
                    return x[1] - x[0] < y[1] - y[0];
                return x[1] < y[1];
            }
        );

        int result = 0;
        int right = INT_MIN;
        for(auto &interval : intervals) {
            if (interval[0] >= right) {
                right = interval[1];
            } else {
                ++result;
            }
        }
        return result;
    }
};


int main()
{
 
}