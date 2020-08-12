#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        ++rowIndex;
         vector<vector<int>> r;
         if (rowIndex == 0) {
             vector<int> emp;
            return emp;
         }
        
        vector<int> tmp;
        tmp.push_back(1);
        
        r.push_back(tmp);
        
        for(int i = 2; i <= rowIndex; i++) {
            
            vector<int> t;
            t.push_back(1);
        
            vector<int> p = r.back();
            for(int j = 1; j < p.size(); j++) {
                t.push_back(p[j-1] + p[j]);
            }
            t.push_back(1);
            r.push_back(t);
            
            
        }
        return r.back();
    }
};

int main()
{
  
}