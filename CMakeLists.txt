# used to declare minimum supported cmake version for project
cmake_minimum_required (VERSION 3.28.3)

# project info here
project (
    "HelloWorld"        # used as name of solution
    VERSION 1.2.3.4     # project version
    LANGUAGES C CXX     # languages used in solution
)

# highly suggested variables for cpp project
set (CMAKE_CXX_STANDARD           20)
set (CMAKE_CXX_STANDARD_REQUIRED  ON)
set (CMAKE_CXX_EXTENSIONS         OFF)

# used to declare and define variables, accessed using ${EXE_NAME}, ${LIB_NAME}
set (EXE_NAME "hello_world")
set (LIB_NAME "libfuncs")

# setting path where all cmake submodules are present
set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}\\cmake")

# option is also used to declare variables and their value can by ON/OFF only, we can also give hint
# such variables can be used in if-else conditions
option (COMPILE_EXE "Whether to compile and generate exe or not" ON)

# when changed below configs, delete the build folder to reflect changes
option (ENABLE_WARNINGS "Enable warnings" ON)
option (ENABLE_WARNINGS_AS_ERRORS "Enable warnings as error" ON)

if (ENABLE_WARNINGS)
  include (warnings)
endif ()

# including submodule from cmake folder
include (git_submodule)
include (docs)

# calling the function added in submodule
add_git_submodule (xlibs\\json)

# if statement takes an option variable
if (COMPILE_EXE)
  # used to declare subdirectories where other cmake files are present
  add_subdirectory (configs)
  add_subdirectory (xlibs)
  add_subdirectory (src)
  
  # we can display message using message
  message ("cmake build successful")
else ()
  # else block body
endif ()

#[[
Different Linking Types:

    - consider following linking to understand linking types

        target_link_libraries (A Public B)
        target_link_libraries (A Private C)

        target_link_libraries (D Public/Private A)

1. Public
    - When A links B as public, it says that A uses B in its implementation and B is also used in A's public API
    - hence D can use B since it is a part of the public API of A

2. Private
    - When A links C as private, it says that A uses C in its implementation but C is not used in any part of A's public API
    - hence D cannot use C since it is not a part of the public API of A

3. Interface
    - In general it is used only for header-only libraries

]]

#[[
basic steps:
    1. Create code and cmake file (CMakeLists.txt)
    2. mkdir build
    3. cd build
  * 4. cmake ..             => configure cmake
  * 5. cmake --build .      => to build executable
    6. run executable

more commands:
  * 1. cmake --build . --target <target_name>

       => compiling only a single target
       => target_name can be libfuncs, hello_world, etc.

    2. cmake .. -G "Visual Studio 17 2022"

       => -G flag is used to specify the visual studio version we want to use

    3. cmake -DCMAKE_BUILD_TYPE=Release ..

       => used to set the build type
       => possible options are Debug, Release, RelWithDebInfo, and MinSizeRel
       => https://stackoverflow.com/questions/48754619/what-are-cmake-build-type-debug-release-relwithdebinfo-and-minsizerel

    4. cmake -DMY_OPTION=[ON|OFF] ..

       => used to pass option values from command line

others:
    1. file and folder names and their paths can be written with and without double quotes

Videos skipped/not practiced:
- Video 23,28   - Dependency Graph
- Video 24      - Fetch Content
- Video 26-27   - Unit testing using external libraries

]]
