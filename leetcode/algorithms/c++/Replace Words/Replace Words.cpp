class Node
{
public:
    vector<Node *> t;
    bool isEnd;
    Node()
    {
        t.resize(26);
        isEnd = false;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = new Node();
    }

    void add(string &x)
    {
        Node *tmp = root;
        for (auto &i : x)
        {
            if (tmp->t[i - 'a'] == NULL)
            {
                tmp->t[i - 'a'] = new Node();
            }
            tmp = tmp->t[i - 'a'];
        }
        tmp->isEnd = true;
    }

    string search(string &x)
    {
        string r = "";
        Node *tmp = root;
        for (auto &i : x)
        {
            if (tmp->isEnd)
                return r;
            if (tmp->t[i - 'a'] == NULL)
                return x;
            tmp = tmp->t[i - 'a'];
            r += i;
        }
        return r;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Tree *tree = new Tree();
        for (auto &x : dictionary)
            tree->add(x);

        string r = "";
        string tmp = "";
        for (auto &i : sentence)
        {
            if (i != ' ')
            {
                tmp += i;
            }
            else
            {
                //  cout << tmp << endl;
                r += tree->search(tmp) + ' ';
                tmp = "";
            }
        }
        //  cout << tmp << endl;
        r += tree->search(tmp);
        return r;
    }
};