#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int n, t[MX], t_max, result;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
        t_max = max(t_max, t[i]);
    }

    for(int i = 0; i < n; i++) 
        result += t_max - t[i];
    printf("%d\n", result);
}