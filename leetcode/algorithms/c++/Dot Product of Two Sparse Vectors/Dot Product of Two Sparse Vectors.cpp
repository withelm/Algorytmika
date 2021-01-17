class SparseVector
{
public:
    vector<int> x;
    SparseVector(vector<int> &nums)
    {
        x = nums;
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        int result = 0;
        for (int i = 0; i < vec.x.size(); i++)
        {
            result += vec.x[i] * x[i];
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);