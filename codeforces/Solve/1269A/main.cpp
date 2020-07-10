#include <cstdio>

const int MX = 10000000 + 101;

bool is_not_prime[MX];
int n;

void generate_prime()
{
    is_not_prime[0] = true;
    is_not_prime[1] = true;
    is_not_prime[2] = false;

    for(int i = 2; i <MX; i++) {
        for(int j = i + i; j < MX; j += i) {
            is_not_prime[j] = true;
        }
    }
}

int main()
{
    generate_prime();
    scanf("%d", &n);

    int first_index = MX - 1;
    int second_index = first_index - n;

    while (!is_not_prime[first_index] || !is_not_prime[second_index])
    {
        --first_index;
        --second_index;    
    }
    printf("%d %d\n", first_index, second_index);
    
}