#include <cstdio>
#include <algorithm>

using namespace std;

int x1, y1, x2, y2;

int min_x, min_y, max_x, max_y;


int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    min_x = min(x1, x2);
    max_x = max(x1, x2);
    min_y = min(y1, y2);
    max_y = max(y1, y2);

    int diff_x = abs(max_x - min_x);
    int diff_y = abs(max_y - min_y);

    printf("%d\n", max(diff_x, diff_y));

}