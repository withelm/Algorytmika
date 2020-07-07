#include <cstdio>

const int MX = 100;
int t, n, a;
int odd_count, even_count;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        odd_count = 0;
        even_count = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (i % 2 == 0 && a % 2 == 1)
                ++odd_count; 
            if (i % 2 == 1 && a % 2 == 0) 
                ++even_count;
        }
        if (odd_count == even_count) {
            printf("%d\n", odd_count);
            continue;
        }
        printf("%d\n", -1);
    }
}