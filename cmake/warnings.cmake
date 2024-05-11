# creating a function to set warnings
#   function name => target_set_warnings
#   parameters => TARGET (target name)
#              => ENABLE (if we want to enable warnings)
#              => ENABLED_AS_ERRORS (if we want to treat warnings as an error)
function (target_set_warnings TARGET ENABLE ENABLED_AS_ERRORS)

    message ("Target: ${TARGET}, Warnings enable: ${ENABLE}, Treat warnings as errors: ${ENABLED_AS_ERRORS}")

    # if user don't want to set warnings, show below message
    if (Not ${ENABLED})

        message (STATUS "Warnings disabled for: ${TARGET}")
        return ()

    endif ()

    # Compiler options for warnings for different compilers
    set (

        MSVC_WARNINGS
        /W4
    )

    set (

        CLANG_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
    )

    set (GCC_WARNINGS ${CLANG_WARNINGS})

    # Append compiler option to treat warnings as error
    if (${ENABLED_AS_ERRORS})

        set (MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
        set (CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
        set (GCC_WARNINGS ${GCC_WARNINGS} -Werror)

    endif ()

    # set the variable WARNINGS with correct warning based on compiler name
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")

        set (WARNINGS ${MSVC_WARNINGS})

    elseif (CMAKE_CXX_COMPILER_ID MATCHES "CLANG")

        set (WARNINGS ${CLANG_WARNINGS})

    elseif (CMAKE_CXX_COMPILER_ID MATCHES "GCC")

        set (WARNINGS ${GCC_WARNINGS})

    endif ()

    # adding compiler options to target, options are added to specific target only
    target_compile_options (${TARGET} PRIVATE ${WARNINGS})

    # show relevant message after setting warnings
    message (STATUS ${WARNINGS})

endfunction ()
