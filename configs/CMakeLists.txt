# this is used to auto generate configurable files
#   binary path => CMAKE_BINARY_DIR
configure_file (
    "configs.hpp.in" # input file which serves as template for file to be generated
    "${CMAKE_BINARY_DIR}\\configured_files\\include\\configs.hpp" ESCAPE_QUOTES # path where file is to be generated
)
