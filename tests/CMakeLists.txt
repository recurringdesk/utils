set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(string ./string.cpp ../source/utils/string.cpp ../source/console/logger.cpp)
add_test(NAME string COMMAND string)

add_executable(print ./print.cpp ../source/utils/string.cpp ../source/console/logger.cpp)
add_test(NAME print COMMAND print)
