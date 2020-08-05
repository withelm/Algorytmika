#include <cstdio>
#include <vector>

using namespace std;

const int MX = 100 + 10;
char word[MX];
int n, k;
int index_g, index_t;

vector<int> queue;

int main()
{
    scanf("%d%d%s", &n, &k, word);

    for(int i = 0; i < n; i++) {
        if (word[i] == 'G') {
            index_g = i;
            word[i] = '.';
        }
        if (word[i] == 'T') {
            index_t = i;
            word[i] = '.';
        }
    }

    word[index_g] = '#';
    queue.push_back(index_g);

    for(int i = 0; i < queue.size(); i++) {
        if (queue[i] + k < n && word[queue[i] + k] == '.') {
            queue.push_back(queue[i] + k);
            word[queue[i] + k] = '#';
        }
        if (queue[i] - k >= 0 && word[queue[i] - k] == '.') {
            queue.push_back(queue[i] - k);
            word[queue[i] - k] = '#';
        }
    }

    if (word[index_t] == '#')
        puts("YES");
    else 
        puts("NO");

}