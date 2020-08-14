#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    vector<string> getParts(string x)
    {
        vector<string> result;
        int index = 0;
        int stack = 0;
        string tmp = "";
        while(index < x.size()) {
            if (x[index] == '(') {
                ++stack;
            } else {
                --stack;
            }
            tmp += x[index];
            if (stack == 0) {
                result.push_back(tmp);
                tmp = "";
            }
            ++index;
        }
        return result;
    }

public:
    string removeOuterParentheses(string S) {
        string result = "";

        vector<string> parts = getParts(S);
        for(auto &part : parts) {
            part.erase(0, 1);
            part.erase(part.size() - 1);
            result += part;    
        }
        return result;
    }
};

int main()
{
    
}