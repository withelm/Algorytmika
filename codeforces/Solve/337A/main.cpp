#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100;
int t[MX];
int n, m;
int result;

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", t + i);

    sort(t, t + n); 
    result = 1000 * 50 + 1;
    for(int i = 0; i + m - 1 < n; i++) {
        result = min(result, t[i + m - 1] - t[i]);
    }
    printf("%d", result);
}