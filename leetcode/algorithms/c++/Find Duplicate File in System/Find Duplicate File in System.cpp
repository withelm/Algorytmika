class Solution
{
private:
    map<string, vector<string>> base;

    void calc(string &item)
    {
        string basePath = "";
        int index = 0;
        int n = item.size();

        while (item[index] != ' ')
        {
            basePath += item[index];
            ++index;
        }
        ++index;

        while (index < n)
        {
            string fileName = "";
            string fileContent = "";
            while (item[index] != '(')
            {
                fileName += item[index];
                ++index;
            }
            ++index;
            while (item[index] != ')')
            {
                fileContent += item[index];
                ++index;
            }
            base[fileContent].push_back(basePath + "/" + fileName);
            index += 2;
        }
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        for (auto &item : paths)
        {
            calc(item);
        }
        vector<vector<string>> result;
        for (auto &x : base)
        {
            if (x.second.size() > 1)
            {
                result.push_back(x.second);
            }
        }
        return result;
    }
};