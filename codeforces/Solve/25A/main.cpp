#include <cstdio>

int n, a;
int odd, even;
int last_odd, last_even;


int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a % 2 == 0) {
            ++even;
            last_even = i;
        } else {
            ++odd;
            last_odd = i;
        }
        
    }
    if (even == 1)
        printf("%d", last_even);
    else
        printf ("%d", last_odd);
}