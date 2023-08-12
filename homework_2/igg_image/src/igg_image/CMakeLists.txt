#################### Import the 'io_tools' library here ########################
find_library(GIVEN_LIB 
             NAMES "libio_tools"
             PATHS ${LIBRARY_OUTPUT_PATH})

if(${GIVEN_LIB} STREQUAL "GIVEN_LIB-NOTFOUND")
    message(FATAL_ERROR "Couldn't find the given library in its path")
endif()

#################### Create a library 'image' below this line ##################
add_library(image image.cpp)
target_link_libraries(image ${GIVEN_LIB})

add_executable(main main.cpp)
target_link_libraries(main image)
