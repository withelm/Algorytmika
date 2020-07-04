#include <cstdio>

const int MX = 255 + 10;

int t[MX];
int n;
char c;

int main()
{
    while (~scanf("%c", &c))
    {
        if (c >= '0' && c <= '9')  {
            ++t[c];
            ++n;
        }
    }
    
    char index = '1';
    while(n > 1) {
        for(int j = 0; j < t[index]; j++) {
            --n;
       
            printf("%c+",index);
            if (n == 1) 
                break;
        }
        ++index;
    }
    for(char i = '3'; i >= '1'; i--) {
        if (t[i] > 0) {
            printf("%c",i);
            return 0;
        }
    }
}
