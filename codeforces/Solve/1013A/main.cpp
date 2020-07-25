#include <cstdio>

int n, sum_x, sum_y, x, y;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum_x += x;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &y);
        sum_y += y;
    }
    if (sum_x < sum_y) 
        puts("No");
    else 
        puts("Yes");
}