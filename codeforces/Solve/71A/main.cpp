#include <cstdio>
#include <cstring>


using namespace std;

const int MX = 100 + 10;

int n;
char word[MX];

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%s", word);
        int size_word = strlen(word);
        if (size_word> 10) {
            printf("%c%d%c\n", word[0], size_word - 2, word[size_word - 1]);
        } else {
            printf("%s\n", word);
        }

    }
}