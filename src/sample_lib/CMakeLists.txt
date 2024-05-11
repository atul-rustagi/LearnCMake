# used to generate library:
#   library name => libfuncs
#   sources => lib.cpp
add_library (${LIB_NAME} STATIC "lib.cpp")

# used to set the include directories folder (where we are having hpp files)
target_include_directories (
    ${LIB_NAME} PUBLIC
    "..\\..\\include"
    "${CMAKE_BINARY_DIR}\\configured_files\\include"
)
