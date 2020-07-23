#include <cstdio>
#include <algorithm>

using namespace std;

const int RED = 2;
const int GREEN = 5;
const int BLUE = 8;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);

    int c_red = n * RED;
    int c_green = n * GREEN;
    int c_blue = n * BLUE;

    int r_red = c_red / k + (c_red % k != 0);
    int r_green = c_green / k + (c_green % k != 0);
    int r_blue = c_blue / k + (c_blue % k != 0);
    
    printf("%d", r_red + r_green + r_blue);
    
}