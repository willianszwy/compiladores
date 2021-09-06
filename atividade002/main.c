#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rpn.h"
#include "calc.h"

// main
int main(int argc, char **argv)
{
  if (argc > 1)
  {
    for (int i = 1; i < argc; ++i)
    {
      char *r = convert_rpn(argv[i]);
      //printf("%s\n", r);
      printf("%f\n", calculate(r));
    }
  }
  else
  {
    char str[2048];

    while (scanf("%s", str) != EOF)
    {
      printf("%f\n", calculate(convert_rpn(str)));
    }
  }

  return EXIT_SUCCESS;
}