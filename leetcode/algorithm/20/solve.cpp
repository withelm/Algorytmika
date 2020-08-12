#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' ||s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else {
                if (stack.size() == 0) return false;
                if (
                    (s[i] == ')' && stack.top() == '(') ||
                    (s[i] == ']' && stack.top() == '[') ||
                    (s[i] == '}' && stack.top() == '{')

                    ) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }

        }
        return stack.size() == 0;
    }
};

int main()
{

}