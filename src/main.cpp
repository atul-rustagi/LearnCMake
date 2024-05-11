#include <stdio.h>

#include "configs.hpp"
#include "lib.hpp"

int main ()
{
    printf ("From main function\n");
    printf ("\tC++ standard used: %d (_MSVC_LANG)\n\n", _MSVC_LANG);
    printf ("\tProject name: %s\n", gProjectName);
    printf ("\tProject version: %s\n", gProjectVersion);
    printf ("\tMajor ver: %d\n", gMajorVersion);
    printf ("\tMinor ver: %d\n", gMinorVersion);
    printf ("\tPatch ver: %d\n", gPatchVersion);
    printf ("\tTweak ver: %d\n\n", gTweakVersion);

    LibFunc ();

    return 0;
}
