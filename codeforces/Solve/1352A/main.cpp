#include <cstdio>
#include <vector>

using namespace std;

vector<int> generate_part_round_number(int x) 
{
    vector<int> result;
    int power10 = 1;
    while(x > 0) {
        if (x % 10 != 0)
            result.push_back((x % 10) * power10);
        power10 *= 10;
        x /= 10;
    }
    return result;
}

int t, n;

int main()
{   
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector<int> result = generate_part_round_number(n);
        printf("%d\n", result.size());
        for(auto i : result) {
            printf("%d ", i);
        }
        printf("\n");
    }
}