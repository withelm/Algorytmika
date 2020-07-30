#include <cstdio>
#include <math.h>

using namespace std;

int t, l, r;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &l, &r);

        
        if (l * 2 <= r) {
            printf("%d %d\n", l, l * 2);
        } else {
            printf("-1 -1\n");
        }
    }
    
}