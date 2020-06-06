/* Standard Headers */
#include <argp.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Local Headers */
#include "algor.h"
#include "dformat.h"
#include "functions.h"

/* ========================================================================= */
struct algor_config_t algor_config = {
    .cwd = "-",
    .questwd = "-",
    .testwd = "-",
    .compwd = "-",
    .flags = 0x0
};
/* ========================================================================= */


int main (int argc, char *argv[]){
    extern struct algor_config_t algor_config;
    char a[100];
    printB("%s\n%s\n%s\n%s\n", algor_config.cwd,
                               algor_config.questwd,
                               algor_config.testwd,
                               algor_config.compwd);
    printf("Enter a string: ");
    getsB(a, 100);
    printBH("%s",a);

    printH("%s", "Hello");
    printB("%s", "Hello");
    printBH("%s", "Hello");
    print_error("%s", "testing");

    return 0;
}
