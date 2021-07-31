class Solution {
private:
    map<vector<char>, int> base;
    
    int MOD = 1e9 + 7;
    
    void init()
    {
        for(char i = '1'; i <= '9'; i++) {
            base[{i}] = 1;
            if (i == '1') {
                for(char j = '0'; j <= '9'; j++) {
                    base[{i, j}] = 1;
                }
                base[{i, '*'}] = 9;
            } 
            if (i == '2') {
                for(char j = '0'; j <= '6'; j++) {
                    base[{i, j}] = 1;
                }
                base[{i, '*'}] = 6;
            }
            
        }
        for(char i = '0'; i <= '6'; i++)
            base[{'*', i}] = 2;
        for(char i = '7'; i <= '9'; i++)
            base[{'*', i}] = 1;
        
        base[{'*'}] = 9;
        base[{'*','0'}] = 2;
        base[{'*', '*'}] = 15;
        
        
        
    }
    
    int simple(string &s) {
        
        int n = s.size();
        long long int first = 1;
        long long int sec = base[{s[0]}];
        
        for(int i = 1; i < n; i++) {
            int n_first = sec;
            int n_sec = ((base[{s[i]}] * sec) % MOD + (base[{s[i - 1], s[i]}] * first) % MOD) % MOD;
            
            sec = n_sec;
            first = n_first;
           
        }
        
        return sec;
    }
public:
    int numDecodings(string s) {
        init();
        return simple(s);
    }
};