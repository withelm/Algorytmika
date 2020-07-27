#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;

int n, t[MX], m, x1, y1;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
        scanf("%d", t + i);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &x1, &y1);
        --x1;
        if (t[x1] >= y1) {
            
            if (x1 - 1 >= 0) {
                t[x1 - 1] += max(y1 - 1, 0);
            }
            if (x1 + 1 < n) {
                t[x1 + 1] += max(0, t[x1] - y1);
            }
            t[x1] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
}