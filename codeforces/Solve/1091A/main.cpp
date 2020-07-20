#include <cstdio>
#include <algorithm>

using namespace std;

int y, b, r;
int result;

int main()
{
    scanf("%d%d%d", &y, &b, &r);

    for(int i = 1; i <= y; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= r; k++) {
                if (j == i + 1 && k == j + 1) {
                    result = max(result, i + j + k);
                }
            }
        }
    }
    printf("%d", result);
}