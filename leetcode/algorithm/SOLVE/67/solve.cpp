#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
 string addBinary(string a, string b) {
        reverse(a.begin(), a.end()); 
        reverse(b.begin(), b.end()); 
        if (a.size() < b.size()) {
            string c = a;
            a = b;
            b = c;
        }
        
        int sum = 0;
        string result = "";
        for(int i = 0; i < b.size(); i++) {
            sum += (a[i] - '0') + (b[i] - '0');
         
            result += (sum % 2) + '0';
            sum /= 2;
        }
        for(int i = b.size(); i < a.size(); i++) {
            sum += a[i] - '0';
            result += (sum % 2) + '0';
            sum /= 2;
        }
        if (sum > 0)
            result += "1";
        
        reverse(result.begin(), result.end()); 
        return result;
    }
};

int main()
{
   
}