#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 50 + 10;

int data[2][MX];
int n, c;

int limak, radewoosh;
int time;

int main()
{
    scanf("%d%d", &n, &c);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    time = 0;
    for(int i = 0; i < n; i++) {
        time += data[1][i];
        limak += max(0, data[0][i] - c * time);
    }

    time = 0;
    for(int i = n - 1; i >= 0; i--) {
        time += data[1][i];
        radewoosh += max(0, data[0][i] - c * time);
    }

    if (limak > radewoosh) {
        puts("Limak");
    } else if (limak < radewoosh) {
        puts("Radewoosh");
    } else {
        puts("Tie");
    }
}