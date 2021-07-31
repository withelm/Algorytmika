class MinTree {
private:
    int MX = 1 << 16;
    int HALF = MX >> 1;
    int DEFAULT = 1e9;
    vector<int> tree;
public:
    MinTree()
    {
        tree.resize(MX);
        for(auto &x : tree)
            x = DEFAULT;
    }
    void insert(int x, int val)
    {
        x += HALF;
        tree[x] = val;
        while(x != 1) {
            x /= 2;
            tree[x] = min(tree[2*x] , tree[2*x + 1]);
        }
    }
    int top() 
    {
        return tree[1];
    }
};
class MaxTree {
private:
    int MX = 1 << 16;
    int HALF = MX >> 1;
    int DEFAULT = -1;
    vector<int> tree;
public:
    MaxTree()
    {
        tree.resize(MX);
        for(auto &x : tree)
            x = DEFAULT;
    }
    void insert(int x, int val)
    {
        x += HALF;
        tree[x] = val;
        while(x != 1) {
            x /= 2;
            tree[x] = max(tree[2*x] , tree[2*x + 1]);
        }
    }
    int top() 
    {
        return tree[1];
    }
};
class Solution {
private:
    MinTree tree_min;
    MaxTree tree_max;
    
    bool check(vector<int> &nums, int split)
    {
        tree_max.insert(split + 1, nums[split]);
        tree_min.insert(split + 1, 1e9);
        return tree_max.top() <= tree_min.top();
    }
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
      
        for(int i = 0; i < n; i++) {
            tree_min.insert(i + 1, nums[i]);
        }
        
        for(int i = 0; i < n; i++)  {
            if (check(nums, i))
                return i + 1;
        }
        return n;
    }
};