#include <cstdio>
#include <algorithm>

using namespace std;

int t, x[3];

int main()
{
    scanf("%d", &t);
    while(t--) 
    {
        scanf("%d%d%d", x, x + 1, x + 2);
        sort(x, x + 3);
        if (x[0] == x[1] == x[2]) {
            printf("YES\r\n");
            printf("%d %d %d\n", x[0], x[0], x[0]);
        } else {
            if (x[1] == x[2]) {
                printf("YES\r\n");
                printf("%d %d %d\n", x[0], x[0], x[1]);
            } else {
                printf("NO\r\n");
            }
        }

    }
}