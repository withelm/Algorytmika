#include <cstdio>

char hate_that[] = "I hate that ";
char hate_it[] = "I hate it";
char love_that[] = "I love that ";
char love_it[] = "I love it";

int n;

int main()
{
    scanf("%d", &n);

    bool isHate = true;
    while (n--) {
        if (n == 0) {
            if (isHate)
                printf("%s", hate_it);
            else printf("%s", love_it);

        } else {
            if (isHate) 
                printf("%s", hate_that);
            else printf("%s", love_that);
        }
        isHate = !isHate;
    }
}