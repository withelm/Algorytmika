#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int t[MX], n, k;

bool check(int *t, int n, int k)
{
    int awruk = 0;
    int elodreip = 0;

    for (int i = 0; i < n; i++) {
        awruk += t[i];
        elodreip += k - t[i];
    }
    return awruk >= elodreip;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
        k = max(k , t[i]);
    }

    while(check(t, n, k)) {
        ++k;
    }
    printf("%d\n", k);
}