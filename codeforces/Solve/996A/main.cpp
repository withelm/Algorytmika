#include <cstdio>

int t[] = {100, 20, 10, 5, 1};
int n, result;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 5; i++) {
        result += n / t[i];
        n %= t[i];
    }
    printf("%d", result);
}