#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    for (int i = 0; i < 10; i++)
    {
        memset(malloc(10 * 1024 * 1024), '0', 10 * 1024 * 1024);//10 - MB
        sleep(1);
    }

    return 0;
}