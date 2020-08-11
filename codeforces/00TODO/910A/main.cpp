#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int n, d;
char word[MX];
int t[MX];

int main()
{
    scanf("%d%d%s", &n, &d, word);
    for(int i = 0; i < n; i++) {
        t[i] = -1;
    }

    t[0] = 0;
    for(int i = 1; i < n; i++) {
        if (word[i] == '1') {
            printf("> search for %d\n", i);
            int result = -1;
            for(int j = i - 1, tmp_d = 0; j >= 0 && tmp_d < d; j--, ++tmp_d) {
                printf(">> %d\n", j);
                if (word[j] == '1') {
                    result = min(result, t[j]);
                }
            }
            if (result == -1)
                t[i] = -1;
            else 
                t[i] = result + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
    puts("");


    printf("%d\n", t[n - 1]);
}