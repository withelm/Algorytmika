#include <cstdio>
#include <map>

using namespace std;
int s;

map<int, int> datas;

int main()
{
    for(int i = 0; i < 4; i++) {
        scanf("%d", &s);
        ++datas[s];
    }
    printf("%d", 4 - datas.size());
}