#include <stdio.h>
#include <string.h>

int main() 
{
    char string[512];

    printf("Enter your string:\n");
    scanf("%s", &string);
    
    printf("Your reversed string:\n");
    int lenght = strlen(string);

    for (int i = lenght-1; i >= 0; i--) 
    {
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;
}