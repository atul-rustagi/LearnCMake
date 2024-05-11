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
#   binary path => CMAKE_BINARY_DIR
target_include_directories (
    ${LIB_NAME} PUBLIC
    "..\\..\\include"
    "${CMAKE_BINARY_DIR}\\configured_files\\include"
)

if (${ENABLE_WARNINGS})

    target_set_warnings (${LIB_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})

endif ()

if (${ENABLE_LTO})

    target_enable_lto (${LIB_NAME} ${ENABLE_LTO})

endif ()
