#include <cstdio>

const int MX = 1e6 + 100;

bool is_not_prime[MX];
int n, m;

void generate_prime()
{
    is_not_prime[0] = true;
    is_not_prime[1] = true;
    for(int i = 2; i < MX; i++) {
        if (!is_not_prime[i]) {
            for(int j = i + i; j < MX; j += i) {
                is_not_prime[j] = true;
            }
        }
    }
}

int main()
{
    generate_prime();

    scanf("%d", &n);
    m = 1;
    while (!is_not_prime[n * m + 1])
    {
        ++m;
    }
    printf("%d", m);

}