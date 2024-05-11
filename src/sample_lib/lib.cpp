#include <stdio.h>

#include "configs.hpp"
#include "lib.hpp"

void LibFunc ()
{
    printf ("Inside LibFunc function\n\n");
    printf ("\tProject name: %s\n", gProjectName);
    printf ("\tProject version: %s\n", gProjectVersion);
}
