#include <cstdio>

int t, n ,m;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        if (n % m == 0)
            puts("YES");
        else 
            puts("NO");
    }
}