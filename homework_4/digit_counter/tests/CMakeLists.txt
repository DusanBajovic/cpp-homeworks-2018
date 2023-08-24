add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(test_digit_counting test_digit_counting.cpp)
target_link_libraries(test_digit_counting
                      digit_counting
                      gtest gtest_main)

#add_test(test_digit_counting tests/test_digit_counting)