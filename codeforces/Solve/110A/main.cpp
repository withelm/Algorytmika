#include <cstdio>
#include <vector>

using namespace std;

const long long int MX = 1000000000 + 10;
const int MX2 = 100;
vector<long long int> lucky_number;

char word[MX2];


void generate_lucky_number()
{
    int index_begin = 0;
    int index_end = 2;
    lucky_number.push_back(4);
    lucky_number.push_back(7);
    long long int power_10 = 10;
    while(power_10 < MX) {
        for(int i = index_begin; i < index_end; i++) {
            lucky_number.push_back( 4 * power_10 + lucky_number[i] );
            lucky_number.push_back( 7 * power_10 + lucky_number[i] );

        }
        index_begin = index_end;
        index_end = lucky_number.size();
        power_10 *= 10;
    }
}

bool isAlmostLuck(long long int x) {
    for(vector<long long int>::iterator it = lucky_number.begin(); it != lucky_number.end(); it++) {
        if (x == *it) {
            return true;
        }
            
    }
    return false;
}

int sum_lucky(char *word) {
    int index = 0;
    int result = 0;
    while(word[index]) {
        if (word[index] == '4' || word[index] == '7')
            ++result;
        ++index;
    }
    return result;
}

int main()
{
    generate_lucky_number();
    scanf("%s", &word);
    if (isAlmostLuck( sum_lucky(word))) {
        printf("YES");
    } else {
        printf("NO");
    }

}