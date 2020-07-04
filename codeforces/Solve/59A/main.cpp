#include <cstdio>

const int MX = 100 + 10;
char word[MX];
int big_char;
int lower_char;
int index;

void change_char(char *word, char from, char to) {
    char from_last = from + ('Z' - 'A');
    for(int i = 0; word[i]; i++) {
        if (word[i] >= from && word[i] <= from_last) {
            word[i] = word[i] - from + to;
        }
    }
}

int main()
{
    scanf("%s", word);
    while(word[index]) {
        big_char += word[index] >= 'A' && word[index] <= 'Z';
        lower_char += word[index] >= 'a' && word[index] <= 'z';
        ++index;
    }    
    if (big_char > lower_char) {
        change_char(word, 'a', 'A');
    } else {
        change_char(word, 'A', 'a');
    }
    printf ("%s", word);
}