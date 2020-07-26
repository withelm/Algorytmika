#include <cstdio>

int n, m, k;
int column, row;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    
    column = ((k - 1) / (2 * m));
    for(int i = 0; i < m; i++) {
        int left = 1 + (m*2)*column + i*2;
        int right = left + 1;
        if (k == left) {
            printf("%d %d L", column + 1, i + 1);
            return 0;
        }
        if (k == right) {
            printf("%d %d R", column + 1, i + 1);
            return 0;
        }
    }

}