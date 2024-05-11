#include <stdio.h>

#include "nlohmann/json.hpp"

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

    printf ("\tNlohmann JSON Lib Version: %d.%d.%d\n\n",
            NLOHMANN_JSON_VERSION_MAJOR, NLOHMANN_JSON_VERSION_MINOR, NLOHMANN_JSON_VERSION_PATCH);

    LibFunc ();

    return 0;
}
