#include <cstdio>

const int MX = 100 + 10;
int n, a, t[MX];
int result;

static inline int max(int x, int y) 
{
    return x > y ? x : y;
}

static inline int min(int x, int y)
{
    return x < y ? x : y;
}

int find_max(int *t, int n) 
{
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(t[i], result);
    }
    return result;
}

int find_min(int *t, int n) 
{
    int result = 100 + 10;
    for (int i = 0; i < n; i++) {
        result = min(t[i], result);
    }
    return result;
}

int find_index_right(int *t, int n, int search_value) 
{
    for(int i = 0; i < n; i++) {
        if (t[i] == search_value)
            return i;
    }
}

int find_index_left(int *t, int n, int search_value)
{
    for(int i = n - 1; i >= 0; i--) {
        if (t[i] == search_value)
            return i;
    }
}

int main()
{  
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
    }
    int max_value = find_max(t, n);
    int max_index = find_index_right(t, n, max_value);
    int min_value = find_min(t, n);
    int min_index = find_index_left(t, n, min_value);
    result = max_index + (n - min_index) - (min_index < max_index) - 1;
    printf("%d", result);
}