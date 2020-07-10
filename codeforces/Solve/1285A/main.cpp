#include <cstdio>

const int MX = 100000 + 10;
char word[MX];
int n;
int l, r;

int main()
{
    scanf("%d%s", &n, word);
    
    for(int i = 0; word[i]; i++) {
        l += word[i] == 'L';
        r += word[i] == 'R';
    }
    printf("%d\n", l + r + 1);
    
}