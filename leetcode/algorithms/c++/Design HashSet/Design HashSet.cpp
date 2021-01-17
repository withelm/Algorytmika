class MyHashSet
{
private:
    set<int> base;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        base.insert(key);
    }

    void remove(int key)
    {
        base.erase(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return base.find(key) != base.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */