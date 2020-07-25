#include <cstdio>
#include <algorithm>

using namespace std;

int t[3];

int main()
{
    scanf("%d%d%d", t, t + 1, t + 2);
    sort(t, t + 3);
    int tmp = t[2] - t[0] - t[1];
    printf("%d\n", tmp < 0 ? 0 : tmp + 1); 
}