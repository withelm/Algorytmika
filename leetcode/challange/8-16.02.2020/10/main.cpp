#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const string LIMIT = "FXSHRXW";

string next_string(string source) 
{
    
    reverse(source.begin(), source.end());
    
    int count = 0;
    for(int i = 0; i < source.size(); i++) {
        ++source[i];
        if (source[i] > 'Z') {
            ++count;
            source[i] = 'A';
        } else {
            break;
        }
    }
    if (count == source.size())
        source.push_back('A');
    reverse(source.begin(), source.end());
    return source;

}

bool check(string v)
{
    
    for(int i = 1; i < v.size(); i++) {
        if (v[i] != 'A')
            return false;
    }
    return true;
}

int main()
{
    string start = "A";
    int result = 1;

    while(start != LIMIT) {
        if (check(start))
            cout << start << " " << result << endl;
        start = next_string(start);
        ++result;
    }
    cout <<result << endl;

}