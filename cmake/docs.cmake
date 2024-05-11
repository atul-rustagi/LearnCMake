# cmake function to find package
#   package name => Doxygen
find_package (Doxygen)

if (DOXYGEN_FOUND)

    # not used to compile something
    # it is used to execute something on terminal
    add_custom_target (

        docs
        ${DOXYGEN_EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}\\docs
    )

else ()

    message ("Doxygen not found")

endif ()
