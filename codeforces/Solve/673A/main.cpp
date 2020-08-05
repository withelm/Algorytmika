#include <cstdio>
#include <algorithm>

using namespace std;

int n, t, result;

int main()
{
    scanf("%d", &n);
    result = 15;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (result < t) {
            printf("%d", result);
            return 0;
        }
        result = t + 15;
    }
    
    printf("%d", min(result, 90));
}