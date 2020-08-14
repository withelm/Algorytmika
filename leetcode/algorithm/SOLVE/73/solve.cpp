#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if (rows.find(i) != rows.end() || columns.find(j) != columns.end())
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    
}