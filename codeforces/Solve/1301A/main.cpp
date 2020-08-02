#include <cstdio>


const int MX = 100 + 10;

char a[MX], b[MX], c[MX];
int t, n;

bool solver()
{
    int index = 0;
    while(a[index]) {

        if (a[index] == c[index]) {
            ++index;
            continue;
        }
        if (b[index] == c[index]) {
            ++index;
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%s%s%s", a, b, c);
        puts(solver() ? "YES" : "NO");
    }
}