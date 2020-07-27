#include <cstdio>

const int MX = 1e5 + 10;

long double right, left, tmp;
int d, l, v1, v2;

long double calc_diff(int a, int b, int v1, int v2, long double time)
{
    long double a_way = time * v1;
    long double b_way = b - (time * v2);

    return b_way - a_way;

}

int main()
{
    scanf("%d%d%d%d", &d, &l, &v1, &v2);

    right = MX;
    left = 0;

    int loop = MX;
    while(loop--) {
        tmp = (right + left) / 2;
        
        long double tmp_r = calc_diff(0, l, v1, v2, tmp);
        if (tmp_r  < d) {
            right = tmp;
        } else {
            left = tmp;
        }

    }
    printf("%.20Lf", tmp);
    
}