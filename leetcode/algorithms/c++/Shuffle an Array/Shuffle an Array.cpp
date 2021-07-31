class Solution {
private:
    vector<int> org;
    
public:
    Solution(vector<int>& nums) {
        org = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> response = org;
        vector<int> curr = org;    
        for(int i = 0; i < response.size(); i++) {
            int index = rand() % curr.size();
            response[i] = curr[index];
            curr.erase(curr.begin() + index);
        }
        return response;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */