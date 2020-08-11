#include <cstdio>

const int MX = 1e2 + 10;
char word[MX];
int n, s, f;

int main()
{
    scanf("%d%s", &n, word);
    for(int i = 0; i < n - 1; i++) {
        if (word[i] != word[i + 1]) {
            if (word[i] == 'F') {
                ++f;
            } else {
                ++s;
            }
        }
    }
    if (s > f) 
        puts("YES");
    else 
        puts("NO");
}