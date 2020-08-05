#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 10;
int t[MX], n;


int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", t + i);

    if (n == 1) {
        printf("%d", t[0]);
        return 0;
    }

    sort(t, t+n);

    while(t[0] < t[n - 1]) {
        ++t[0];
        --t[n - 1];
    }
    printf("%d", t[0]);
}