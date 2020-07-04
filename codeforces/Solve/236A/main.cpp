#include <cstdio>

const int MX = 255 + 10;
int t[MX];
int count;
char c;

int main()
{
    while(~scanf("%c", &c)) {
        ++t[c];
        if (t[c] == 1)
            ++count;
    }
    if (count % 2 == 1) {
        printf("CHAT WITH HER!");
    } else {
        printf("IGNORE HIM!");
    }
}