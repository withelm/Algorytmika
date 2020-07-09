#include <cstdio>

int t, n;

int main()
{
    scanf("%d" ,&t);
    while(t--) {
        scanf("%d", &n);
        if ((n / 2) % 2 == 1) {
            puts("NO");
            continue;
        }

        puts("YES");
        int sum = 0;
        for (int i = 0; i < n / 2; i++) {
            printf("%d ", (i + 1) * 2);
            sum += (i + 1) * 2;
        }
        int current_value = 1;
        for (int i = 0; i < n / 2 - 1; i++) {
            printf("%d ", current_value);

            sum -= current_value;
            current_value += 2;

        }
        printf("%d\n", sum);
    }
}