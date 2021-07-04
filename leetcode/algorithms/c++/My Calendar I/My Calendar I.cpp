class MyCalendar
{
private:
    vector<vector<int>> list;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto &item : list)
        {
            if (item[1] > start && item[0] < end)
                return false;
        }
        list.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */