
class Solution {
private:
 
    
public:
    string alienOrder(vector<string>& words) {
        map<char, vector<char>> conn;
        map<char, int> kub;
        
        for(auto &word : words) {
            for (auto &x : word) {
                kub[x] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            auto w1 = words[i];
            auto w2 = words[i + 1];
            if (w1.size() > w2.size() && w1.rfind(w2, 0) == 0) {
                return "";
            }
            for(int j  = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    conn[w1[j]].push_back(w2[j]);
                    ++kub[w2[j]];
                    break;
                }
            }
        }
        
        string result = "";
     
        queue<char> q;
        for(auto &c : kub) {
            if (c.second == 0)
                q.push(c.first);
        }
        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            result.push_back(c);
            for(auto next : conn[c]) {
                --kub[next];
                if (kub[next] == 0)
                    q.push(next);
            }
        }
        if (result.size() < kub.size())
            return "";
        return result;
    }
};