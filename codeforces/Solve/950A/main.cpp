#include <cstdio>
#include <algorithm>

using namespace std;

int r, l, a;

int main()
{
    scanf("%d%d%d", &l, &r, &a);

    if (r < l) swap(r, l);
    if (l + a < r) {
        printf("%d", 2 * (l + a));
    } else {
        int result = 2 * r;
        result += ((a - (r - l)) / 2) * 2;
        printf("%d", result);
    } 

}