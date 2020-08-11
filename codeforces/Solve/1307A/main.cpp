#include <cstdio>

const int MX = 1e3 + 100;
int a[MX], n, d, t, result;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &d);
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i]; j++) {
                if (i <= d) {
                    ++result;
                    d -= i;
                }
            }
        }
        printf("%d\n", result);
    }
}