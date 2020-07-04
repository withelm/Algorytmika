#include <cstdio>

char c;
char last_char;
int count;

bool check()
{
    if (count >= 7) {
        printf("YES");
        return true;
    }
    return false;
}

int main()
{

    while(~scanf("%c", &c)) {
        if (last_char != c) {
            last_char = c;
            if (check()) {
                return 0;
            }
            count = 1;
            continue;
        }
        ++count;
    }
    if(!check()) {
        printf("NO");
    }
}