public class MyLinkedList
{
    private List<int> _source;
    /** Initialize your data structure here. */
    public MyLinkedList()
    {
        _source = new List<int>();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int Get(int index)
    {

        if (_source.Count() > index)
            return _source[index];
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void AddAtHead(int val)
    {

        _source.Insert(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    public void AddAtTail(int val)
    {

        _source.Add(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void AddAtIndex(int index, int val)
    {

        if (index == _source.Count()) AddAtTail(val);
        else if (index < _source.Count())
            _source.Insert(index, val);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void DeleteAtIndex(int index)
    {

        if (index < _source.Count())
            _source.RemoveAt(index);
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */