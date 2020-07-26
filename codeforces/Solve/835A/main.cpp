#include <cstdio>

int s, v1, v2, t1, t2, r1, r2;

int main()
{
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    r1 = t1 * 2 + s * v1;
    r2 = t2 * 2 + s * v2;
    if (r1 < r2) {
        puts("First");
    } else if (r1 > r2) {
        puts("Second");
    } else {
        puts("Friendship");
    }

}