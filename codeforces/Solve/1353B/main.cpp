#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 50;

int t;
int n, k;
int a[MX], b[MX];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", b + i);
        }
        sort(a, a + n);
        sort(b, b + n);

        int index_a = 0;
        int index_b = n - 1;
        for(int i = 0; i < k && a[index_a] < b[index_b]; i++) {
            a[index_a] = b[index_b];
            ++index_a;
            --index_b;
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            result += a[i];
        }
        printf("%d\n", result);
    }
}