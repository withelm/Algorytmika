/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution
{

private:
    void addToMap(PolyNode *x, map<int, int> &base)
    {
        while (x != NULL)
        {
            //cout << x->power << " " << x->coefficient << " " << endl;
            base[x->power] += x->coefficient;
            x = x->next;
        }
    }

public:
    PolyNode *addPoly(PolyNode *poly1, PolyNode *poly2)
    {
        map<int, int> base;
        addToMap(poly1, base);
        addToMap(poly2, base);
        vector<vector<int>> k;
        for (auto &x : base)
        {
            if (x.second != 0)
                k.push_back({x.first, x.second});
        }

        reverse(k.begin(), k.end());

        PolyNode *tmp = new PolyNode();
        PolyNode *r = tmp;

        for (auto &x : k)
        {
            tmp->next = new PolyNode(x[1], x[0]);
            tmp = tmp->next;
        }

        return r->next;
    }
};