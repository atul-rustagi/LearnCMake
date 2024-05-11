#include <stdio.h>

#include "configs.hpp"
#include "lib.hpp"

void LibFunc ()
{
    printf ("Inside LibFunc function\n\n");
    printf ("\tProject name: %s\n", gProjectName);
    printf ("\tProject version: %s\n", gProjectVersion);
    printf ("\tMajor ver: %d\n", gMajorVersion);
    printf ("\tMinor ver: %d\n", gMinorVersion);
    printf ("\tPatch ver: %d\n", gPatchVersion);
    printf ("\tTweak ver: %d\n\n", gTweakVersion);
}
