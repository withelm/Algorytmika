#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 1e6;

int calc(char from, char to) 
{
    int index = 0;
    char right = from;
    char left = from;
    while( right != to && left != to ) {
        ++index;
        ++right;
        --left;
        if (right > 'z')
            right = 'a';
        if (left < 'a')
            left = 'z';
    }
    return index;
}

char word[MX];
int result;
char current = 'a';

int main()
{
    scanf("%s", word);
    
    for(int i = 0; word[i]; i++) {
        result += calc(current, word[i]);
        current = word[i];
    }
    printf("%d", result);
}