#include <cstdio>

const int MX = 50 + 10;
const int MX2 = 1000 * 5;

int t, n, s[MX];

static inline int abs(int x) 
{
    return x > 0 ? x : -x;   
}

static inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main() 
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", s + i);

        int result = MX2;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                result = min(result, abs(s[i] - s[j]));
            }
        }
        printf("%d\n", result);
    }
}