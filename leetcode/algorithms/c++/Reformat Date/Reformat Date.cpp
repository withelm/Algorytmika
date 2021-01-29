class Solution
{
private:
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    string reformatDate(string date)
    {
        int day = date[0] - '0';
        int index = 1;
        if (date[index] >= '0' && date[index] <= '9')
            day = day * 10 + date[index++] - '0';
        index += 3;
        string monthStr = "";
        for (int i = 0; i < 3; i++)
            monthStr += date[index++];
        int month = 0;
        for (int i = 0; i < months.size(); i++)
        {
            if (months[i] == monthStr)
            {
                month = i + 1;
                break;
            }
        }
        ++index;
        int year = 0;
        for (int i = 0; i < 4; i++)
        {
            year = year * 10 + (date[index++] - '0');
        }

        if (day < 10 && month < 10)
            return to_string(year) + "-0" + to_string(month) + "-0" + to_string(day);
        if (day < 10 && month >= 10)
            return to_string(year) + "-" + to_string(month) + "-0" + to_string(day);
        if (day >= 10 && month < 10)
            return to_string(year) + "-0" + to_string(month) + "-" + to_string(day);

        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};