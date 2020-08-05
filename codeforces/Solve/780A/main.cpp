#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<int> data;
int n, x;
int result;
int tmp_result;

int main()
{
    scanf("%d", &n);
    n *= 2;
    while(n--) {
        scanf("%d", &x);
        if (data.find(x) == data.end()) {
            ++tmp_result;
            data.insert(x);
        } else {
            data.erase(x);
            --tmp_result;
        }
        result = max(result, tmp_result);
    }
    printf("%d", result);
}