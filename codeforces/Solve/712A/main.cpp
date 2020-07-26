#include <cstdio>

const int MX = 1e5 + 100;
int a[MX];
int b[MX];
int n;


static inline int get_sign(int n, int i)
{
    if (n % 2 != 0) {
        if (i % 2 == 0) 
            return 1;
        else    
            return -1;   
    }
    if (i % 2 == 1) 
            return 1;
        else    
            return -1; 
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", a + i);

    b[n] = a[n];
    
    for(int i = n - 1; i >= 1; i--) {
       b[i] = a[i] + a[i + 1];
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", b[i]);
}