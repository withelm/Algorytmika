#include <cstdio>

#include <cstring>


const int MX = 100 + 10;
char word_s[MX], word_t[MX];

int main()
{
    scanf("%s%s", word_s, word_t);

    int index_begin = 0;
    int index_last = strlen(word_s) - 1;
    int loop = strlen(word_s);
    while(loop--) {
        if (word_s[index_begin] != word_t[index_last]) {
            puts("NO");
            return 0;
        }
        ++index_begin;
        --index_last;
        
    }
    puts("YES");

}