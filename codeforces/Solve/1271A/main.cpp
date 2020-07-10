#include <cstdio>

int t, s, v, j, e, f;
int t2, s2, v2, j2;
int first_sum, second_sum;

int tmp_min;

static inline int min(int x, int y)
{
    return x < y ? x : y;
}

static inline int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    scanf("%d%d%d%d%d%d", &t, &s, &v, &j, &e, &f);
    t2 = t;
    s2 = s;
    v2 = v;
    j2 = j;

    tmp_min = min(t, j);    
    first_sum = tmp_min * e;
    t -= tmp_min;
    j -= tmp_min;
    tmp_min = min(s, min(j, v));
    first_sum += tmp_min * f;

    
    tmp_min = min(s2, min(j2, v2));
    second_sum = tmp_min * f;
    s2 -= tmp_min;
    j2 -= tmp_min;
    v2 -= tmp_min;
    second_sum += min(t2, j2) * e;

    printf("%d", max(first_sum, second_sum));
    

}