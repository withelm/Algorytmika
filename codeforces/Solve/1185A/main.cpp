#include <cstdio>
#include <algorithm>

using namespace std;

int t[3], d;

int main()
{
    scanf("%d%d%d%d", t, t+1, t+2, &d);

    sort(t, t + 3);
    int left = abs(t[1] - d - t[0]);
    int right =  abs(t[1] + d - t[2]);
    int result = 0;
    if (abs(t[0] - t[1]) < d)
        result += left;
    if (abs(t[1] - t[2]) < d)
        result += right;

    printf("%d", result);
}