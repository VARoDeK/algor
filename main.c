#include <stdio.h>
#include <string.h>
#include "dformat.h"
#include "functions.h"

int main(){
  char a[10];
  fgetsH(a, 10, stdin);
  printB("%s",a);
  printH("%s",a);
  printBH("%s",a);
  print_error("%s",a);
}
