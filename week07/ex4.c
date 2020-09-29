#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void* myRealloc(void* ptrmem, size_t size)
{
    if(ptrmem == NULL)
    {
        return malloc(size);
    }

    if(size == 0)
    {
        free(ptrmem);
    }

    void *nptr = malloc(size);
    if (nptr == NULL) {
        return NULL;
    }
    
    memcpy(nptr, ptrmem, sizeof(ptrmem));
    free(ptrmem);
    return nptr;
}

int main()
{
    return 0;
}