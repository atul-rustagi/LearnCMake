# creating a function to enable LTO
#   function name => target_enable_lto
#   parameters => TARGET (target name)
#              => ENABLE (if we want to enable LTO)
function (target_enable_lto TARGET ENABLE)

    if (Not ${ENABLED})

        message (STATUS "LTO disabled for: ${TARGET}")
        return ()

    endif ()

    # CheckIPOSupported is inbuild file in cmake
    include (CheckIPOSupported)

    # checking if IPO is supported by our compiler
    check_ipo_supported (RESULT result OUTPUT output)

    # do the needful
    if (result)

        message (STATUS "IPO/LTO is supported and is enabled")
        set_property (TARGET ${TARGET} PROPERTY INTERPROCEDURAL_OPTIMIZATION ${ENABLE})

    else ()

        message (STATUS "IPO/LTO is not supported")

    endif ()

endfunction ()
