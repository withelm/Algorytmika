#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
 
using namespace std;
 
string word;
 
 
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}
 
 
static inline void rtrim(std::string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
 
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
 
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        trim(token);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
 
set<string> datas;
 
int main()
{
    getline(cin, word);
 
    word.erase(0, 1);
    word.erase(word.size() - 1);
 
 
 
    vector<string> result = split(word, ",");
    for(auto &item : result) {
        datas.insert(item);
    }
    cout << datas.size();
 
}