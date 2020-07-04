#include <cstdio>
#include <cstring>

const int MX = 100 + 10;
const int MX2 = 6;
char word[MX];

char block[MX2] = {'a', 'o', 'y', 'e', 'u', 'i'};

bool check(char x) {
    for(int i = 0; i < MX2; i++) {
        if (x == block[i])
            return true;
    }
    return false;
}

int main()
{
    scanf("%s", word);
    int index = 0;
    while (word[index])
    {
        if (word[index] >= 'A' && word[index] <= 'Z')
            word[index] = word[index] - 'A' + 'a';
        
        if (!check(word[index])) {
            printf(".%c", word[index]);
        }
        
        ++index;
    }
    
}