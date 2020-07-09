#include <cstdio>

int a, b, t;

int solve_problem(int a, int b) 
{
    if (a == b)
        return 0;
    if (a > b) {
        if ((a - b) % 2 == 1)
            return 2;
        return 1;
    }
    if ((b - a) % 2 == 0)
        return 2;
    return 1;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", solve_problem(a, b));
    }
}