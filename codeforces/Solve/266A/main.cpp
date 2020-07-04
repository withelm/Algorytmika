#include <cstdio>

char c;
char last_char;
int count;
int n;

int main()
{
    scanf("%d\n", &n);
    while(n--) {
        scanf("%c", &c);
        if (last_char != c) {
            last_char = c;
            continue;
        }
        ++count;
    }

    printf("%d", count);
}