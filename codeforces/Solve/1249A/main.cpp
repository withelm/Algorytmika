#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int q, n, t[MX];


bool check()
{
    for(int i = 1; i < n; i++) {
        if (t[i] - t[i - 1] == 1)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", t + i);
        sort(t, t + n);
        if (check())
            puts("2");
        else 
            puts("1");
    }
}