#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, c, n, t;
int tab[3];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", tab, tab + 1, tab + 2, &n);
        sort(tab, tab + 3);
        
        a = tab[0];
        b = tab[1];
        c = tab[2];

        if (n < c + c - b - a) {
            puts("NO");
            continue;
        }

        if ((n - c - c + b + a) % 3 == 0)
            puts("YES");
        else
            puts("NO");
    }
}