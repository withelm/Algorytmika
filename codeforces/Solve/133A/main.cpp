#include <cstdio>

char c;

int main()
{
    while(~scanf("%c", &c)) {
        if (c == 'H' || c == 'Q' || c == '9') {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}