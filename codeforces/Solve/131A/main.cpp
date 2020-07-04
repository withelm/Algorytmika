#include <cstdio>

const int MX = 100 + 10;
int upper_case;
int len;
char word[MX];

void repair(char *word, bool isBegin = true)
{
    for(int i = 0; word[i]; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] - 'A' + 'a';
    }
    if (isBegin && word[0] >= 'a' && word[0] <= 'z') {
        word[0] = word[0] - 'a' + 'A';
    }
}

int main()
{
    scanf("%s", word);
    for(int i = 0; word[i]; i++) {
        upper_case += word[i] >= 'A' && word[i] <= 'Z';
        ++len;
    }
    if (upper_case + 1 == len && word[0] >= 'a' && word[0] <= 'z') {
        repair(word);
    }
    if (upper_case == len) {
        repair(word, false);
    }
    printf("%s", word);
}