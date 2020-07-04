#include <cstdio>
#include <cstring>


int n, a, b;
int current_value;
int result;

inline int max(int a, int b){
    return a > b ? a : b;
}

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d",&a,&b);
        result = max(current_value, result);
        current_value -= a;
        result = max(current_value, result);
        current_value += b;
        result = max(current_value, result);
    }
    printf("%d", result);
}