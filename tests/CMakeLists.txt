add_executable(string ./string.cpp)
target_link_libraries(string PRIVATE recore)
add_test(NAME string COMMAND string)

add_executable(print ./print.cpp)
target_link_libraries(print PRIVATE recore)
add_test(NAME print COMMAND print)

add_executable(window ./window.cpp)
target_link_libraries(window PRIVATE regui recore)
add_test(NAME window COMMAND window)