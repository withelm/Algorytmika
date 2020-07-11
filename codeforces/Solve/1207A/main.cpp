#include <cstdio>
#include <algorithm>
using namespace std;
int t, b, p ,f, h, c;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
        if (h < c) {
            swap(p, f);
            swap(h, c);
        }
        int result = 0;
        while(b >= 2 && p > 0) {
            b -= 2;
            --p;
            result += h;
        }
        while(b >= 2 && f > 0) {
            b -= 2;
            --f;
            result += c;
        }
        printf("%d\n", result);
    }
}