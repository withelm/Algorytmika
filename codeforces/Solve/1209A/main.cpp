#include <cstdio>

const int MX = 100 + 10;
int n;
bool is_color[MX];
int a, result;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        is_color[a] = true;
    }
    
    for (int i = 1; i < MX; i++) {
        if (is_color[i]) {
            ++result;
            for(int j = i; j < MX; j += i) {
                is_color[j] = false;
            }
        }
    }
    printf("%d\n", result);
}