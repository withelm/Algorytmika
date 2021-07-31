
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> r(length, 0);
        
        for(auto &item : updates) {
            r[item[0]] += item[2];
            if (item[1] + 1 < length)
                r[item[1] + 1] -= item[2];
     
        }

        for(int i = 1; i < length; i++)
            r[i] += r[i - 1];
        return r;
    }
};