#include <cstdio>
#include <cstring>

const int MX = 1000 + 10;
char word[MX];
char search[] = "heidi";

bool isSubstringInWord(char* word, char* substring)
{
    int word_size = strlen(word);
    int substring_size = strlen(substring);

    int substring_index = 0;
    for (int i = 0; substring_index < substring_size && word[i]; i++) {
        if (word[i] == substring[substring_index]) {
            ++substring_index;
        }
    }
    return substring_index == substring_size;
}

int main()
{
    scanf("%s", word);
    if (isSubstringInWord(word, search)) {
        puts("YES");
    } else {
        puts("NO");
    }

}