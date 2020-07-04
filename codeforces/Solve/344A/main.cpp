#include <cstdio>

int n, a, result;
int last_a;

int main()
{
    scanf("%d",&n);
    while(n--) {
        scanf("%d", &a);
        if (a != last_a) {
            ++result;
            last_a = a;
        }
    }
    if (a != last_a)
        ++result;
    printf("%d", result);
}