#include <cstdio>

const int MX = 1e9 + 10;

int n, a, last_a, result, result_part;

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    scanf("%d", &n); 
    last_a = MX;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (last_a <= a) {
            ++result_part;
            last_a = a;
        } else {
            result = max(result_part, result);
            result_part = 1;
            last_a = a;
        }
    }
    result = max(result_part, result);
    printf("%d", result);
}