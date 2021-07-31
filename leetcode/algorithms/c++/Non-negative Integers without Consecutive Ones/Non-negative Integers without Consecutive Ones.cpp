class Solution {
private:
    int MX = 32;
public:
    int findIntegers(int n) {
        vector<int> fib = {1, 2};
        for(int i = 2; i < MX; i++) 
            fib.push_back(fib[i - 1] + fib[i - 2]);
        int result = 0;
        int old_bit = 0;
        for(int i = 30; i >= 0; i--) {
            if ((n & (1 << i)) != 0) {
                result += fib[i];
                if (old_bit == 1) {
                    --result;
                    break;
                }
                old_bit = 1;
            } else {
                old_bit = 0;
            }
        }
        return result + 1;
    }
}; 