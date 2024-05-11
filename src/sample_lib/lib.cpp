/**
 * @file lib.cpp
 * @author Atul RUstagi (06atul1998@gmail.com)
 * @brief file which is used to give example of generating static library and linking using CMake
 * @version 1.0
 * @date 2024-03-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#include "configs.hpp"
#include "lib.hpp"

/**
 * @brief This function is present in static library which gets linked to main object file
 *        This also prints project name and version
 * 
 */
void LibFunc ()
{
    printf ("Inside LibFunc function\n\n");
    printf ("\tProject name: %s\n", gProjectName);
    printf ("\tProject version: %s\n", gProjectVersion);
}
