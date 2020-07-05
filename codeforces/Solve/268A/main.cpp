#include <cstdio>

const int MX = 30 + 10;
int t[MX][2];
int n, result;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &t[i][0], &t[i][1]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            if (t[i][0] == t[j][1]) 
                ++result;
        }
    }
    printf("%d", result);
}