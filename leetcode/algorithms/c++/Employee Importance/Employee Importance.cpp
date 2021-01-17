/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
private:
    map<int, Employee *> base;

    int dfs(Employee *x)
    {
        if (x == NULL)
            return 0;
        int r = x->importance;
        for (auto &i : x->subordinates)
        {
            r += dfs(base[i]);
        }
        return r;
    }

public:
    int getImportance(vector<Employee *> employees, int id)
    {

        for (auto &x : employees)
            base[x->id] = x;

        return dfs(base[id]);
    }
};