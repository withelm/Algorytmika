#include <cstdio>

const int MX = 10;

inline bool isDistinct(int x)
{
    int t[MX];
    for(int i = 0; i < MX; i++)
        t[i] = 0;

    while(x > 0){
        ++t[x % 10];
        x /= 10;
    }
    for(int i = 0; i < MX; i++) {
        if (t[i] > 1)
            return false;
    }
    return true;
}

int year;

int main()
{
    scanf("%d", &year);
    ++year;
    while (!isDistinct(year))
    {
        ++year;
    }
    printf("%d", year);
    
}