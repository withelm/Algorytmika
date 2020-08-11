#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 1e2 + 10;

int t[MX];
int r[MX];
int n;

int min_diffrent, find_index;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
    }
    t[n] = t[0];

    for(int i = 0; i < n; i++) {
        r[i] = abs(t[i] - t[i + 1]);
    }

    min_diffrent = r[0];
    find_index = 0;

    for(int i = 1; i < n; i++) {
        if (min_diffrent > r[i]) {
            min_diffrent = r[i];
            find_index = i;
        }
    }

    printf("%d %d", find_index + 1, ((find_index + 1) % n) + 1);
}