add_executable(sail_example main.cpp)

add_dependencies(sail_example sail)

target_link_libraries(sail_example PUBLIC sail)