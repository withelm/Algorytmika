#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 10;
const int MAGIC_NUMBER_32 = 32;
const int MAGIC_NUMBER_256 = 256;

int k[MX];
long long int result;
long long int v;

int main()
{
    scanf("%d%d%d%d", k+2, k+3, k+5, k+6);

    v = min(k[2], min(k[5], k[6]));
    result = v * MAGIC_NUMBER_256;
    k[2] -= v;
    k[5] -= v;
    k[6] -= v;

    v = min(k[2], k[3]);
    result += v * MAGIC_NUMBER_32;    
    printf("%lld\n", result);
}