#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 1000 + 10;

int n, a;
struct pair_data
{
    int index, value;
};
pair_data t[MX];

static inline bool cmp(pair_data &x, pair_data &y)
{
    return x.value > y.value;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        t[i].index = i;
        t[i].value = a;
    }
    sort(t, t + n, cmp);
    printf("%d %d", t[0].index + 1, t[1].value);

}