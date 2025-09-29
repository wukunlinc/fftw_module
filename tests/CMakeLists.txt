cmake_minimum_required(VERSION 3.29...4.1)

include(CTest)

find_package(GTest CONFIG REQUIRED)
find_package(FFTW3 CONFIG REQUIRED)

add_executable(fftw_module_mock)
target_sources(fftw_module_mock
               PRIVATE
               fftwl_tests.cpp
               fftwl_mock_class.h
               fftwl_mock.cpp
               fftwf_test.cpp
               fftwf_mock_class.h
               fftwf_mock.cpp
               fftw_tests.cpp
               fftw_mock_class.h
               fftw_mock.cpp
               test_main.cpp)

target_include_directories(fftw_module_mock
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_compile_features(fftw_module_mock PRIVATE cxx_std_20)

set_property(TARGET fftw_module_mock PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_compile_options(fftw_module_mock
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/std:c++20>
          $<$<CXX_COMPILER_ID:MSVC>:/W4>
          $<$<CXX_COMPILER_ID:MSVC>:/WX>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Werror>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>)

if(BUILD_FFTW3_MODULE)
  target_link_libraries(fftw_module_mock PRIVATE GTest::gtest GTest::gmock fftw_cxx_module)  
  target_compile_definitions(fftw_module_mock PRIVATE USE_MODULE)
else()
  target_link_libraries(fftw_module_mock PRIVATE GTest::gtest GTest::gmock)
endif()