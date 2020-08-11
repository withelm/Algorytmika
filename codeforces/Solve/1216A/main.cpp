#include <cstdio>

const int MX = 2 * 1e5 + 100;

char word[MX];
int n, result;

int main()
{
    scanf("%d%s", &n, word);
    for(int i = 0; i < n; i += 2) {
        if (word[i] == word[i + 1]) {
            ++result;
            word[i] = (((word[i] - 'a') + 1) % 2) + 'a';
        }
    }
    printf("%d\n%s\n", result, word);
}