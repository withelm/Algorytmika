#include <cstdio>
#include <algorithm> 

using namespace std;

int n, x, sum, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }

    printf("%d\n", abs(sum) / k + (abs(sum) % k != 0));

}