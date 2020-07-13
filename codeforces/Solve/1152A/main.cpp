#include <cstdio>
#include <algorithm>

using namespace std;

int a[2], b[2];
int n, m, p;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        ++a[p % 2];
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &p);
        ++b[p % 2];
    }
    printf("%d\n", min(a[0], b[1]) + min(a[1], b[0]));    
}