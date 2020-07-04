#include <cstdio>


int n, a;

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        if (a == 1) {
            puts("HARD");
            return 0;
        }
    }
    puts("EASY");
}