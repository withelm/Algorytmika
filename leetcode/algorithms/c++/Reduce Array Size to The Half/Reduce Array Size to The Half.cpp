class Solution {
private:
    map<int, int> dp;
    
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        for(auto &item : arr) {
            ++dp[item];
        }
        
        vector<vector<int>> data;
        
        for(auto &item : dp)
            data.push_back({item.first, item.second});
        
        sort(data.begin(), data.end(), [](const vector<int> &x, const vector<int> &y) {
           return x[1] > y[1]; 
        });
        
        int m = 0;
        int index = 0;
        while(index < data.size() && m * 2 < n) {
            m += data[index][1];
            ++index;
        }
        
        return index;
    }
};