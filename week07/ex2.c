#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int N;

    scanf("%d", N);

    int *values = malloc(N * sizeof(int));

    print(sizeof(values));

    return 0;
}