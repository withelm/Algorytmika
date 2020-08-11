#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MX = 11;

char word[MX];
int n, len;

vector<vector<char> > data;

vector<char> nextSubString(char word[], int n)
{
    int index = 0;
    vector<char> result;

    while(n > 0) {
        if (n % 2 == 1) {
            result.push_back(word[index]);
        }
        n /= 2;
        ++index;
    }
    return result;
}

bool isPalindrome(vector<char> word)
{
    int len = word.size();
    for(int i = 0; i < len; i++) {
        if (word[i] != word[len - i - 1])
            return false;
    }
    return true;
}

bool cmp(vector<char> &a, vector<char> &b)
{
    for(int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main()
{
    scanf("%s", word);
    len = strlen(word);

    for(int i = 0; i < (1 << len); i++) {
        vector<char> result = nextSubString(word, i);
        if (isPalindrome(result)) {
            data.push_back(result);
        }
    }

    sort(data.begin(), data.end(), cmp );

    for(vector<char>::iterator it = data[0].begin(); it != data[0].end(); it++) {
        printf("%c", *it);
    }
    
}