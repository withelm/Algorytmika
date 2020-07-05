#include <cstdio>

const int MX = 255 + 10;
const int ALPHABET_MX = 26;
char word[MX];

bool t[MX];
int n;
int result;

int main()
{
    scanf("%d%s", &n, word);
    for(int i = 0; word[i]; i++) {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] = word[i] - 'a' + 'A';
        result += !t[word[i]];
        t[word[i]] = true;
    }
    if (ALPHABET_MX == result)
        puts("YES");
    else
        puts("NO");
    
}