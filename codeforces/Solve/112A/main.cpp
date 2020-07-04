#include <cstdio>
#include <cstring>

const int MX = 100 + 10;
char word_first[MX], word_second[MX];

int main()
{
    scanf("%s%s", word_first, word_second);

    int index = 0;
    while(word_first[index]) {
        if (word_first[index] >= 'A' && word_first[index] <= 'Z')
            word_first[index] = word_first[index] - 'A' + 'a';
        if (word_second[index] >= 'A' && word_second[index] <= 'Z')
            word_second[index] = word_second[index] - 'A' + 'a';
      
        if (word_first[index] < word_second[index]) {
            printf("-1");
            return 0;
        }
        if (word_first[index] > word_second[index]) {
            printf("1");
            return 0;
        }
        ++index;
    }
    printf("0");
    return 0;
}