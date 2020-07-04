#include <cstdio>
#include <vector>

using namespace std;

const int MX = 1000;

vector<int> lucky_number;
int n;

bool isLuck(int x) {
    while (x > 0) {
        int mod = x % 10;
        if (mod != 4 && mod != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

bool isAlmostLuck(int x) {
    for(vector<int>::iterator it = lucky_number.begin(); it != lucky_number.end(); it++) {
        if (x % *it == 0)
            return true;
    }
    return false;
}

int main()
{
    for(int i = 1; i <= MX; i++) {
        if (isLuck(i)) {
            lucky_number.push_back(i);
        }
    }

    scanf("%d", &n);
    if (isAlmostLuck(n)) {
        printf("YES");
    } else {
        printf("NO");
    }
}