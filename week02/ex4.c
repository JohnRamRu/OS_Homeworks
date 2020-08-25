#include <stdio.h>

void swap_by_adress(int *first, int *second) 
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int main()
{
    int first, second;

    printf("Please, enter first integer:\n");
    scanf("%d", &first);
    printf("Please, enter second integer:\n");
    scanf("%d", &second);

    printf("First integer is %d. Second integer is %d\n", first, second);
    swap_by_adress(&first, &second);
    printf("Now first integer is %d. Second integer is %d\n", first, second);

    return 0;
}