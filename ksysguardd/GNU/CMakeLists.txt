include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../CContLib ${CMAKE_CURRENT_SOURCE_DIR}/../)

add_library(libksysguardd STATIC
            dummy.cpp)

