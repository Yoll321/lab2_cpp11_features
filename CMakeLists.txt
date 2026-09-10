cmake_minimum_required(VERSION 3.10)

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