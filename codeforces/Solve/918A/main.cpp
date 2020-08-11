#include <cstdio>

const int MX = 1e4 + 100;

char word[MX];
int n;
int a, b, c;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        word[i] = 'o';

    a = 1;
    b = 1;
    c = 2;

    word[1] = word[2] = 'O';
    while(b + c <= n) {
        int tmp = b + c;
        a = b;
        b = c;
        c = tmp;
        word[c] = 'O';
    }
    word[n + 1] = 0;
    printf("%s", word + 1);
}