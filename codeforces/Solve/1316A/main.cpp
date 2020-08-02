#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, m, a, current_student;
int tmp_sum;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        scanf("%d", &current_student);
        tmp_sum = 0;
        for(int i = 1; i < n; i++) {
            scanf("%d", &a);
            tmp_sum += a;
        }
        current_student = min(m, current_student + tmp_sum);
        printf("%d\n", current_student);
    }
}