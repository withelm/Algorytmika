#include <cstdio>

const int MX = 100 + 10;
char word[MX];

int main()
{
    scanf("%s", word);
    if (word[0] >= 'a' && word[0] <= 'z')
        word[0] = word[0] - 'a' + 'A';
    printf("%s", word);

}