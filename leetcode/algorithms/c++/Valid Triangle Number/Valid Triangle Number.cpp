class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            int k = i + 2;
            if (nums[i] == 0) 
                continue;
            for(int j = i + 1; j < n ; j++) {
                
                while(k < n && nums[i] + nums[j] > nums[k])
                    ++k;
                r += k - j - 1;
            }
        }
        return r;
    }
};