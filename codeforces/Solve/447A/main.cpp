#include <cstdio>

const int MX = 300 + 100;
bool isConflict[MX];
int p, n, x;

int main()
{
    scanf("%d%d", &p, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (isConflict[x % p]) {
            printf("%d", i + 1);
            return 0;
        }
        isConflict[x % p] = true;
    }
    puts("-1");
}