#include <cstdio>

int h, m, t;
int result;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &h, &m);

        result = (24 - h - 1) * 60;
        result += 60 - m;
        printf("%d\n", result);
    }
}