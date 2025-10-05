# Project Setup
cmake_minimum_required(VERSION 3.29...4.1)

string(REGEX MATCH "^Visual Studio.*" MSVC_SELECTED "${CMAKE_GENERATOR}")

if(MSVC_SELECTED)
    set(VCPKG_TARGET_TRIPLET x64-windows-static)
endif()

project(fftw_module VERSION 0.1
                    DESCRIPTION "C++20 wrapper of FFTW3"
                    LANGUAGES CXX)

include(GNUInstallDirs)

# Build
OPTION(BUILD_FFTW3_MODULE "Build the FFTW3 wrapper as a C++20 module" OFF)
if (BUILD_FFTW3_MODULE)
    add_subdirectory(cxx_module)
endif()

add_library(fftw_module INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
    fftw_module
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(fftw_module
               PRIVATE
               "include/fftw_module/fftw_vector.h"
               "include/fftw_module/fftw_data_support.h"
               "include/fftw_module/fftw_module.h"
               "include/fftw_module/fftw_plan.h")

target_compile_features(fftw_module INTERFACE cxx_std_20)

# Tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
    add_test(NAME fftw_module_mock COMMAND fftw_module_mock)    
    set(CMAKE_SKIP_TEST_ALL_DEPENDENCY FALSE)
endif()


# Installation
install(TARGETS fftw_module
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    
include(CMakePackageConfigHelpers)
write_basic_package_version_file("fftw_module_ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}_Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}_Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}_Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}_ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/fftw_module DESTINATION include)