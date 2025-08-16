add_executable(string ./string.cpp)
target_link_libraries(string PRIVATE recurringcore)
add_test(NAME string COMMAND string)

add_executable(print ./print.cpp)
target_link_libraries(print PRIVATE recurringcore)
add_test(NAME print COMMAND print)
