#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n = RAND_MAX;
    srand(time(NULL));
    printf("\n%d", rand());
    printf("\n%d", rand());
    printf("\n%d", rand());
    printf("\n%d", rand());
    printf("\n%d", rand());
    return 0;
}
