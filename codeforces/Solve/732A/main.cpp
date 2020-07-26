#include <cstdio>

int k, r, result;
int tmp_k;
int main()
{
    scanf("%d%d", &k, &r);
    result = 1;
    tmp_k = k;
    while(tmp_k % 10 != r && tmp_k % 10 != 0) {
        ++result;
        tmp_k += k;
    }
    printf("%d\n", result);
}