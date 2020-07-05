#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
}

static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

static inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}


const string WUB = "WUB";
string word;

int main()
{  
    cin >> word;
    while( replace(word, WUB, " "));
    while( replace(word, "  ", " "));
    trim(word);
    cout << word;
}