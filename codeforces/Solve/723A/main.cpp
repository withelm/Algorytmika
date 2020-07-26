#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 10;
int x[MX];
int v, result;

int main()
{
    scanf("%d%d%d", x, x+1, x+2);
    sort(x, x + 3);
    
    result = x[2] - x[1];
    result += x[1] - x[0];
    
    printf("%d\n", result);
}