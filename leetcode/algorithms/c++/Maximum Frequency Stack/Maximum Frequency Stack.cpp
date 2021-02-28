class Point
{
public:
    int val, index, cnt;
};

class FreqStack
{
private:
    map<int, vector<int>> base;
    map<int, int> convert;
    int index;
    int convert_index;
    int MX = 1 << 16;
    int FULL = MX << 1;

    vector<Point> t;

    void update(int x, int i, int val)
    {
        int id = convert[x] + MX;
        t[id].val = x;
        t[id].index = i;
        t[id].cnt += val;
        id /= 2;
        while (id > 0)
        {
            if (t[id * 2].cnt > t[id * 2 + 1].cnt)
            {
                t[id] = t[id * 2];
            }
            else if (t[id * 2].cnt < t[id * 2 + 1].cnt)
            {
                t[id] = t[id * 2 + 1];
            }
            else if (t[id * 2].index > t[id * 2 + 1].index)
            {
                t[id] = t[id * 2];
            }
            else
            {
                t[id] = t[id * 2 + 1];
            }
            id /= 2;
        }
    }

public:
    FreqStack()
    {
        index = 0;
        convert_index = 0;
        t.resize(FULL);
    }

    void push(int x)
    {
        base[x].push_back(index);
        if (convert.find(x) == convert.end())
        {
            convert[x] = convert_index++;
        }
        update(x, index, 1);

        ++index;
    }

    int pop()
    {
        int result = t[1].val;
        base[result].pop_back();
        update(t[1].val, t[1].cnt == 1 ? 0 : base[result].back(), -1);
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */