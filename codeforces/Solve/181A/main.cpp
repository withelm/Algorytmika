#include <cstdio>

const int MX = 100 + 10;
const int MX2 = 5;

struct point
{
    int x, y;
};

char word[MX];
int n, m;
point t[MX2];
int t_index;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        for(int j = 0; j < m; j++) {
            if (word[j] == '*') {
                t[t_index].x = i + 1;
                t[t_index].y = j + 1;
                ++t_index;
            }
        }
    }
    printf ("%d %d", t[0].x^t[1].x^t[2].x, t[0].y^t[1].y^t[2].y);
}