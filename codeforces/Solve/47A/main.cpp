#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MX = 500 + 100;

vector<int> t;
int n;

int main()
{
    scanf("%d", &n);

    for(int i = 0; (i * (i + 1) / 2) <= MX; i++) {
        t.push_back((i * (i + 1) / 2));
    }    

    if (find(t.begin(), t.end(), n) != t.end()) 
        puts("YES");
    else
        puts("NO");
    
}