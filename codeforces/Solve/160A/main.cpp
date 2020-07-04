#include <cstdio>
#include <algorithm>

using namespace std;

const int MX = 100 + 10;
int t[MX];
int n;


int right_sum;
int sum;
int right_index;
int result = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        sum += t[i];
    }

    sort(t, t+n);
    right_index = n -1;
    
    while(right_sum <= sum / 2) {
        ++result;
        right_sum += t[right_index];
        --right_index;
        
    }
    printf ("%d", result);
    

}