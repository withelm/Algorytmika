#include <cstdio>

int n, m;
double min_cost = 1e5;
int a, b;

int main()
{
    scanf("%d%d", &n, &m);    
    while(n--) {
        scanf("%d%d", &a, &b); 
        double tmp = ((double)a) / b;
        if (min_cost > tmp) {
            min_cost = tmp;
        }
    }
    printf("%f\n", min_cost * m);
}