class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> r = {1};
        while(r.size() < n) {
            vector<int> tmp;
            for(auto &x : r)
                if (2 * x - 1 <= n)
                    tmp.push_back(2*x - 1);
            for(auto &x : r)
                if (2 * x <= n)
                    tmp.push_back(2*x);
            r = tmp;
        }
        return r;
    }
};