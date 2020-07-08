#include <cstdio>
#include <cstring>

const int MX = 1000000 + 10;
int t;
char word[MX];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%s", word);
        printf("%c%c", word[0], word[1]);
        int word_len = strlen(word);
        for(int i = 2;  i < word_len; i += 2) {
            printf("%c", word[i + 1]);
        }
        printf("\n");
    }
}