# cmake folder will contain files to add our own cmake functions
# files are ending with .cmake extension

# used to add our own function
#   function name => add_git_submodule
#   parameters => dir
function (add_git_submodule dir)

    # cmake function to find package
    #   package name => Git
    #   REQUIRED means it is a must have for project to build
    find_package (Git REQUIRED)

    if (NOT EXISTS "${CMAKE_SOURCE_DIR}\\${dir}\\CMakeLists.txt")

        # cmake function to execute user commands
        execute_process (

            # here running git command
            #   variable GIT_EXECUTABLE is set by find_package with absolute git binary path
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive --${CMAKE_SOURCE_DIR}\\${dir}

            # setting working directory from where above command will run
            #   source directory path => PROJECT_SOURCE_DIR
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        )

    endif ()

    if (EXISTS "${CMAKE_SOURCE_DIR}\\${dir}\\CMakeLists.txt")

        message ("Adding ${dir}\\CMakeLists.txt")
        add_subdirectory (${dir})

    else ()

        message ("Could not add ${dir}\\CMakeLists.txt")

    endif ()

endfunction ()
