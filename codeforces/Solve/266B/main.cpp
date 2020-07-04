#include <cstdio>

const int MX = 1000000 + 100;
char word[MX];
char new_word[MX];
int n, t;


int main()
{
    scanf("%d%d%s", &n, &t, word);

    while(t--) {
        for(int i = 0; i < n; i++) {
            if (i + 1 < n && word[i] == 'B' && word[i + 1] == 'G') {
                new_word[i] = 'G';
                new_word[i+1] = 'B';
                ++i;
            } else {
                new_word[i] = word[i];
            }
        }
        for (int i = 0; i < n; i++) {
            word[i] = new_word[i];
        }
    }
    printf("%s", word);
}