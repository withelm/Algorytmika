map<char, int> base;
class Solution {
public:
    string customSortString(string order, string str) {
        
        for(char i = 'a'; i <= 'z'; i++)
            base[i] = 1e9;
        for(int i = 0; i < order.size(); i++) 
            base[order[i]] = i;
        sort(str.begin(), str.end(), [](const char &x, const char &y) {
           return base[x] < base[y]; 
        });
        return str;
    }
};