/**
 * @file main.cpp
 * @author Atul Rustagi (06atul1998@gmail.com)
 * @brief main file for learning CMake
 * @version 1.0
 * @date 2024-03-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#include "nlohmann/json.hpp"

#include "configs.hpp"
#include "lib.hpp"

/**
 * @brief Entry point of program, prints C++ standard used, project name and version.
 * 
 * @return int 
 */
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
