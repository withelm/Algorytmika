#include <cstdio>
#include <cstring>

const int MX = 5;
const char word[] = "hello";
char c;

int main()
{
    int index = 0;
    while(~scanf("%c", &c)) {
        if (word[index] == c)
            ++index;

        if (index == MX) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}