#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, l, c, d, p, nl, np, result;

int main()
{
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
    k *= l;
    c *= d;
   
    result = min(k / nl, min(c, p / np)) / n;
    printf("%d\n", result);
}