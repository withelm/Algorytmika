#include <cstdio>

const int MX = 100 + 10;

char word[MX];
int l, r, n, m;
char c1, c2;

int main()
{
    scanf("%d%d%s", &n, &m, word);
    while(m--) {
        scanf("%d %d %c %c", &l, &r, &c1, &c2);
        for(int i = l - 1; i < r; i++) {
            if (word[i] == c1)
                word[i] = c2;
        }
    }
    printf("%s", word);
}