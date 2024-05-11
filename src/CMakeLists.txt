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
target_link_libraries (${EXE_NAME} PUBLIC ${LIB_NAME})

add_subdirectory (sample_lib)
