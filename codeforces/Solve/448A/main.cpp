#include <cstdio>

int a, tmp_a;
int b, tmp_b;
int n;
int result;

int main()
{
    for(int i = 0; i < 3; i++) {
        scanf("%d", &tmp_a);
        a += tmp_a;
    }
    for(int i = 0; i < 3; i++) {
        scanf("%d", &tmp_b);
        b += tmp_b;
    }
    scanf("%d", &n);
    result += (a / 5) + (a % 5 != 0);
    result += (b / 10) + (b % 10 != 0);
    if (result <= n)
        puts("YES");
    else
        puts("NO");
}