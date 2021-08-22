class Solution {
private:
    map<int, int> toSmall;
    map<int, int> toOrg;
    
    long long int res = 0;
    int MOD = 1e9 + 7;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        for(auto &rec: rectangles)
            for(auto &x : rec)
                toSmall[x] = 0;
        int cnt = 0;
        for(auto &x : toSmall) {
            x.second = cnt++;
            toOrg[x.second] = x.first;
        }
        vector<vector<int>> smallRect;
        for(auto &rec: rectangles)
            for(auto &x : rec)
                toSmall[x] = 0;
        
    }
};