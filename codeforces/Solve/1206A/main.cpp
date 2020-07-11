#include <cstdio>

const int MX = 100 + 10;
const int MX2 = 4 * MX;
int A[MX], n, m;
int B[MX];
bool is_check[MX2];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", A + i);
        is_check[A[i]] = true;
    }
    scanf("%d", &m);
    for(int i = 0 ; i < m; i++) {
        scanf("%d", B + i);
        is_check[B[i]] = true;
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!is_check[A[i] + B[j]]) {
                printf("%d %d\n", A[i], B[j]);
                return 0;
            }
        }
    }
}