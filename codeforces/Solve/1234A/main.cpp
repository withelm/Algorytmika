#include <cstdio>

const int MX = 100 + 10;

int q;
int n, t[MX];

int main()
{
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", t + i);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += t[i];
        }
        printf("%d\n", (sum / n) + (sum % n != 0) );
    }
}