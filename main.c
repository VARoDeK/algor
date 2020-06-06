/* Standard Headers */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Local Headers */
#include "algor.h"
#include "dformat.h"
#include "functions.h"

int main (int argc, char *argv[]){
    char a[100];

    printf("Enter a string: ");
    getsB(a, 100);
    printBH("%s",a);

    printH("%s", "Hello");
    printB("%s", "Hello");
    printBH("%s", "Hello");
    print_error("%s", "testing");

    return 0;
}
