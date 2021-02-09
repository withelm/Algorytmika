class RandomizedSet
{
private:
    map<int, int> base;
    vector<int> t;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (base.find(val) != base.end())
            return false;
        base[val] = t.size();
        t.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (base.find(val) == base.end())
            return false;

        base[t.back()] = base[val];
        t[base[val]] = t.back();
        base.erase(val);
        t.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return t[rand() % t.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */