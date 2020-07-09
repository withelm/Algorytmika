#include <cstdio>

const int MX = 100 + 10;
int t, n;
int tab[MX];

int all_sum() 
{
    int result = 0;
    for(int i = 0; i < n; i++) {
        result += tab[i];
    }
    return result;
}

int all_pro()
{
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= tab[i];
    }
    return result;
}

int add_pro()
{
    int result = 0;
    for(int i = 0; i < n; i++) {
        if (tab[i] == 0) {
            ++tab[i];
            ++result;
        }
    }
    return result;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", tab + i);
        }
        int result = add_pro();
        
        printf("%d\n", result + (all_sum() == 0));
    }
}