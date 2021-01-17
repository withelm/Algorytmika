/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution
{
public:
    int search(const ArrayReader &reader, int target)
    {
        for (int i = 0; i <= 10000; i++)
        {
            if (reader.get(i) == target)
                return i;
        }
        return -1;
    }
};