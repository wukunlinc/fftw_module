cmake_minimum_required(VERSION 3.29...4.1)

find_package(FFTW3 CONFIG REQUIRED)

add_library(fftw_cxx_module)

if(NOT COMMAND configure_cpp_module_target)
    function(configure_cpp_module_target target)
        target_sources(${target} PUBLIC FILE_SET CXX_MODULES FILES fftw_module.cppm)
    endfunction()
endif()

configure_cpp_module_target(fftw_cxx_module)

target_include_directories(fftw_cxx_module
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_link_libraries(fftw_cxx_module
    PRIVATE
    fftw_module::fftw_module
    FFTW3::fftw3
)

target_compile_features(fftw_cxx_module PUBLIC cxx_std_20)

set_property(TARGET fftw_cxx_module PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")