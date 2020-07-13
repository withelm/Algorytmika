#include <cstdio>
#include <algorithm>

int x[4];


int main()
{
    scanf("%d%d%d%d", x, x + 1, x + 2, x + 3);
    std::sort(x, x + 4);
    printf("%d %d %d\n", x[3] - x[0], x[3] - x[1], x[3] - x[2]);
}