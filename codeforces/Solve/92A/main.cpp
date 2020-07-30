#include <cstdio>

int n, m;
int v;

int main()
{
    scanf("%d%d", &n, &m);
    v = 0;
    while (v + 1 <= m)
    {
        m -= v + 1;
        v = (v + 1) % n;
    }
    printf("%d\n", m);
        
}