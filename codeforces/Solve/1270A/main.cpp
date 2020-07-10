#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int t, n, a, b;
int t_a[MX], t_b[MX];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 0; i < a; i++)
            scanf("%d", t_a + i);
        for(int i = 0; i < b; i++)
            scanf("%d", t_b + i);
        sort(t_a, t_a + a);
        sort(t_b, t_b + b);

        if (t_a[a - 1] > t_b[b - 1]) 
            puts("YES");
        else
            puts("NO");
        
    }
}