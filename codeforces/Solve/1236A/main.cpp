#include <cstdio>

int t, a, b, c;

bool remove_1(int &a, int &b, int &c)
{
    if (a >= 1 && b >= 2) {
        a -= 1;
        b -= 2;
        return true;
    }
    return false;
}

bool remove_2(int &a, int &b, int &c)
{
    if (b >= 1 && c >= 2) {
        b -= 1;
        c -= 2;
        return true;
    }
    return false;
}

int calc_1(int a, int b, int c) 
{
    int result = 0;
    while(remove_1(a, b, c)) ++result;
    while(remove_2(a, b, c)) ++result;
    return result;
}

int calc_2(int a, int b, int c) 
{
    int result = 0;
    while(remove_2(a, b, c)) ++result;
    while(remove_1(a, b, c)) ++result;
    return result;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
 
        printf("%d\n", max(calc_1(a,b,c), calc_2(a,b,c)) * 3);
    }
}