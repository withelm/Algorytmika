#include <cstdio>
#include <cmath>
const int MX = 5;
int n;


int main()
{
    for(int i = 1 ;i <=MX; i++) {
        for(int j = 1; j <= MX; j++) {
            scanf("%d", &n);
            if (n == 1) {
                i -= 3;
                j -= 3;
                printf("%d", abs(i) + abs(j));
                return 0;
            }
        }
    }
}