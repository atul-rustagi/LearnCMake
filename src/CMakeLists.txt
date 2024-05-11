# we can create a variable holding all the source files
set (
    EXE_SOURCES
    "main.cpp"
)

# used to generate project and executable:
#   project name => hello_world
#   sources => main.cpp
add_executable (${EXE_NAME} ${EXE_SOURCES})

# used to link library with the executable
target_link_libraries (
    ${EXE_NAME} PUBLIC
    ${LIB_NAME}
    nlohmann_json   # name of external library
)

add_subdirectory (sample_lib)

if (${ENABLE_WARNINGS})

    target_set_warnings (${EXE_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})

endif ()
