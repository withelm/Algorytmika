#include <cstdio>

const int MONTH_DAY[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m, d;

int solver(int m, int d) 
{
    if (MONTH_DAY[m] == 31) {
        if (d <= 5) return 5;
        return 6;
    }
    if (MONTH_DAY[m] == 30) {
        if (d <= 6) return 5;
        return 6;
    }
    if (d == 1) return 4;
    return 5;
}

int main()
{
    scanf("%d%d", &m, &d);
    printf("%d", solver(m, d)); 
}