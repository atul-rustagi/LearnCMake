# we can create a variable holding all the source files
set (
    LIB_SOURCES
    "lib.cpp"
)

# used to generate library:
#   library name => libfuncs
#   sources => lib.cpp
add_library (${LIB_NAME} STATIC ${LIB_SOURCES})

# used to set the include directories folder (where we are having hpp files)
target_include_directories (
    ${LIB_NAME} PUBLIC
    "..\\..\\include"
    "${CMAKE_BINARY_DIR}\\configured_files\\include"
)
