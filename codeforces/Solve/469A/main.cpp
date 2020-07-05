#include <cstdio>

const int MX = 100 + 10;
bool t[MX];
int p, a, n;

bool check(bool *t, int n) 
{
    for(int i = 1; i <= n; i++) {
        if (!t[i])
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 2; i++) {
        scanf("%d", &p);
        while(p--) {
            scanf("%d", &a);
            t[a] = true;
        }
    }
    if (check(t, n)) {
        puts("I become the guy.");
    } else {
        puts("Oh, my keyboard!");
    }
}