class OrderedStream
{
private:
    vector<string> t;
    int i;

public:
    OrderedStream(int n)
    {
        i = 1;
        t.resize(n + 1);
    }

    vector<string> insert(int id, string value)
    {
        t[id] = value;
        vector<string> r;
        for (; i < t.size() && t[i].size() != 0; i++)
        {
            r.push_back(t[i]);
        }
        return r;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */