#include <cstdio>
const int MX = 1000000 + 10;

char word[MX];
int n;

int a, d;

int main()
{
    scanf("%d%s", &n, word);

    for(int i = 0; word[i]; i++) {
        a += word[i] == 'A';
        d += word[i] == 'D';
    }
    if (a > d) {
        puts("Anton");
    } else if(d > a) {
        puts ("Danik");
    } else {
        puts("Friendship");
    }
}