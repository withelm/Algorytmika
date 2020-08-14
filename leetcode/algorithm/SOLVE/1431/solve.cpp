#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candie = -1;
        vector<bool> result;

        for(auto &candie : candies) {
            max_candie = max(max_candie, candie);
        }
        for(auto &candie : candies) {
            result.push_back(candie + extraCandies >= max_candie);
        }
        return result;
    }
};

int main()
{
    
}