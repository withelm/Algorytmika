#include <cstdio>

const int MX = 2000 + 100;
int n, t, a, odd, even;
int sum;

bool check(int odd, int even, int sum)
{
    if (sum % 2 == 1)
        return true;
    if (odd == 0)
        return false;
    if (odd > 0 && even > 0)
        return true;
    return false;    
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        odd = 0;
        even = 0;
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            odd += a % 2;
            even += !(a % 2);    
            sum += a;
        }

        if (check(odd, even, sum)) {
            puts("YES");
        } else {
            puts("NO");
        }
        

    }
}