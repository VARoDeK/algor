/* Standard Headers */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Local Headers */
#include "functions.h"

/* ========================================================================= */

void fgets_imp(char *__restrict __s, int __n, FILE *__restrict __stream){
  char ch;
  uint32_t l;

  fgets(__s, __n, __stream);
  l = strlen(__s);

  if(__s[l-1] != '\n'){
    ch=0;
    while(ch != '\n')
      ch = getchar();
  }

  else {
    __s[l-1] = '\0';
  }

  return;
}
/* ========================================================================= */
