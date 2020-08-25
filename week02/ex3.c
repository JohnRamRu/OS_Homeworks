#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

void straight_triangle(int n) 
{
    char string[BUFFER_SIZE];

    for (int i = 0; i < 2 * n; ++i)
    {
        string[i] = ' '; //filling
    }
    string[2*n-1] = '\0';
    string[n-1] = '*'; //top (middle position)

    for (int i = 1; i < n; ++i) 
    {
        printf("%s\n", string);
        string[n-1-i] = '*';//increase in left side
        string[n-1+i] = '*';//increase in right side
    }
    printf("%s\n", string);//last level
}

void right_triangle(int n) 
{
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= i; ++j) 
        {
            printf("*");
        }
        printf("\n");
    }
}

void rotated_triangle(int n) 
{
    char string[BUFFER_SIZE];
    for (int i = 0; i < n; ++i) 
    {
        string[i] = ' ';
    }
    string[n] = '\0';

    for (int i = 0; i < n; ++i) 
    {
        string[i] = '*';//replacing to middle
        printf("%s\n", string);
    }

    for (int i = n-1; i > 0 ; --i) 
    {
        string[i] = '\0';//re-replacing
        printf("%s\n", string);//in back order (to fill lower levels)
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) {
        printf("Please, provide valid arguments\n");
        return 0;
    }

    char *nParam = argv[1];
    char *typeParam = argv[2];
    int n, type;
    sscanf(nParam, "%d", &n);
    sscanf(typeParam, "%d", &type);
    //printf("%d\n", n);

    switch (type) 
    {
        case 1: 
            straight_triangle(n); 
            break;
        case 2: 
            right_triangle(n); 
            break;
        case 3: 
            rotated_triangle(n); 
            break;
        default: 
            printf("Unknown type of triangle.\nPlease, enter number from 1 to 3.\n");
    }
    return 0;
}