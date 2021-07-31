vector<vector<char>> mem;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        int n = s.size();
        while(end < n) {
            while(end < n && s[end] != ' ') {
                ++end;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = end = end + 1;
        }
       
    }
};