#include <cstdio>
#include <set>

using namespace std;

set<int> data;
int n, a, t;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &a);
            data.insert(a);
        }
        printf("%ld\n", data.size());
        data.clear();
    }
}