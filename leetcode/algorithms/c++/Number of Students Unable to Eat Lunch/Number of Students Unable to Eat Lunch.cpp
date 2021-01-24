class Solution
{

public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int k = 0;
        int limit = students.size();
        limit *= limit;
        while (k < limit && students.size() > 0)
        {

            if (students[0] == sandwiches[0])
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                continue;
            }
            students.push_back(students[0]);
            students.erase(students.begin());
            ++k;
        }
        return students.size();
    }
};