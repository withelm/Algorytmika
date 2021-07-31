class Solution {
private:
    map<int, int> base;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        for(auto &i : nums) ++base[i];
        
        set<vector<int>> r;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int rev_sum = target - nums[i] - nums[j] - nums[k];
                    int cnt = 0;
                    if (nums[i] == rev_sum) ++cnt;
                    if (nums[j] == rev_sum) ++cnt;
                    if (nums[k] == rev_sum) ++cnt;
                    if (base[rev_sum] > cnt) {
                        vector<int> tmp = {nums[i], nums[j], nums[k], rev_sum};
                        sort(tmp.begin(), tmp.end());
                        r.insert(tmp);
                    }
                    
                }
            }
        }
        vector<vector<int>> result;
        for(auto &i : r) result.push_back(i);
        return result;
    }
};