# used to generate project and executable:
#   project name => hello_world
#   sources => main.cpp
add_executable (${EXE_NAME} "main.cpp")

# used to link library with the executable
target_link_libraries (${EXE_NAME} PUBLIC ${LIB_NAME})

add_subdirectory (sample_lib)
