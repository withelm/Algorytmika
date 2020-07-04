#include <cstdio>
#include <cstring>

const int MX = 10;
char word[MX];
int n;
int result;

int main()
{
    scanf("%d\n", &n);
    while(n--) {
        scanf("%s", word);
        if (word[1] == '+')
            ++result;
        else 
            --result;
    }
    printf("%d", result);
}