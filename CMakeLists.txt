cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0167 NEW)

set(PATCH_VERSION "1" CACHE STRING "Patch Version provided by GitHub")
project(ip_filter
    VERSION 1.0.${PATCH_VERSION}
    LANGUAGES CXX)

add_executable(ip_filter)
target_sources(ip_filter
    PRIVATE ip_filter.cpp)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/ip_filter.tsv
    ${CMAKE_CURRENT_BINARY_DIR}/ip_filter.tsv
)
set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

enable_testing()

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_library(ip_filter_lib STATIC ip_filter_lib.cpp)
target_include_directories(ip_filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ip_filter PRIVATE ip_filter_lib)

add_executable(ip_filter_tests 
    tests/test_main.cpp
    tests/test_sort.cpp
    tests/test_parse.cpp
    tests/test_split.cpp)
target_link_libraries(ip_filter_tests 
    PRIVATE 
        ip_filter_lib
        Boost::unit_test_framework)

add_test(
    NAME split_should_split_ip_by_dots
    COMMAND ip_filter_tests --run_test=split_test
)

add_test(
    NAME parse_ip_should_convert_to_uint32
    COMMAND ip_filter_tests --run_test=parse_test
)

add_test(
    NAME sort_should_place_larger_ips_first
    COMMAND ip_filter_tests --run_test=sort_test
)

set(CPACK_PACKAGE_NAME "ip-filter")
set(CPACK_PACKAGE_VENDOR "nom4")
set(CPACK_PACKAGE_CONTACT "nom4@tpu.ru")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "IP Filter C++ application")

if(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif(UNIX)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "nom4@tpu.ru")
endif()

include(CPack)