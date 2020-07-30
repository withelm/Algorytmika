#include <cstdio>
#include <algorithm>

using namespace std;

int y, w;
int up, down;

int gcd(int a, int b)
{
    if(b!=0)
    	return gcd(b,a%b);
	
    return a;
}
int main()
{
    scanf("%d%d", &y, &w);

    up = 6 - max(y, w) + 1;
    down = 6;

    y = gcd(up, down);
    up /= y;
    down /= y;

    printf("%d/%d", up, down);
}