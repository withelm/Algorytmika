#include <cstdio>
#include <algorithm>

using namespace std;

int t,n,x,a,b;
int result;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &x, &a, &b);
        if (a > b) swap(a, b);
        result = 0;
        if (x > a - 1) {
            x -= a - 1;
            result += a - 1;

            if (x > n - b) {
                result += n - b;
            } else {
                result += x;
            }
        } else {
            result += x;
        }
        printf("%d\n", result + b - a);
    }
}