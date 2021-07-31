class Solution {
private:
    bool check(vector<int> &x, vector<int> &y)
    {
        if (x.size() != y.size())
            return false;
        for(int i = 0; i < x.size(); i++) {
            if (x[i] != y[i])
                return false;
        }
        return true;
    }
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(auto &item : arr)
            sum += item;
        
        if (sum % 3 != 0)
            return {-1, -1};
        int part = sum / 3;
        if (part == 0)
            return {0, n - 1};
        
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
       
        int suma = 0;
        for(int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                suma += 1;
     
                if (suma == 1)
                    i1 = i;
                if (suma == part)
                    j1 = i;
                if (suma == part + 1)
                    i2 = i;
                if (suma == part * 2)
                    j2 = i;
                if (suma == part * 2 + 1)
                    i3 = i;
                if (suma == part * 3)
                    j3 = i;
                    
            }
        }
        vector<vector<int>> tmp = {
          vector<int>(arr.begin() + i1, arr.begin() + j1 + 1),
          vector<int>(arr.begin() + i2, arr.begin() + j2 + 1),
          vector<int>(arr.begin() + i3, arr.begin() + j3 + 1),
        };
        if (!check(tmp[0], tmp[1]) || !check(tmp[0], tmp[2])) 
            return {-1, -1};
        int x = i2 - j1 - 1;
        int y = i3 - j2 - 1;
        int z = n - j3 - 1;
        if (x < z || y < z)
            return {-1, -1};
        return {j1 + z, j2 + z + 1};
    }
};