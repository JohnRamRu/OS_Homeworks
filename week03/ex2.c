#include <stdio.h>

void bubble_sort(int* array, size_t size)
{
    for (int i = 0 ; i < size - 1; i++)
    {
        for (int j = 0 ; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1]) /* For decreasing order use < */
            {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }


}

int main()
{
    int size = 5;
    int array[5] = {-150, 8, 96, 34, 2};

    printf("Array before sorting: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }

    bubble_sort(array, size);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; ++i) 
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}