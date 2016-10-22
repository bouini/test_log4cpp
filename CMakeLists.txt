cmake_minimum_required (VERSION 2.6)

set(LOG4CPP_PATH "/Users/nicolas/log4cpp/") 

project(test_log4cpp)

add_executable(test_log4cpp Main.cpp)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
                     ${LOG4CPP_PATH}/include )

add_library(liblog4cpp STATIC IMPORTED)
set_target_properties(liblog4cpp PROPERTIES
    IMPORTED_LOCATION ${LOG4CPP_PATH}/lib/liblog4cpp.a)

target_link_libraries(test_log4cpp liblog4cpp)

