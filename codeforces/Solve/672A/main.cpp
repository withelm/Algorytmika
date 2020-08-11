#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int MX = 1000;

string getString(int x)
{
    string result = "";
    while(x != 0) {
        result += ((x % 10) + '0');
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int n;
string source;

int main()
{
    for(int i = 1; i < MX; i++) {
        source += getString(i);
    }    

    scanf("%d", &n);
    printf("%c", source[n - 1]);
}