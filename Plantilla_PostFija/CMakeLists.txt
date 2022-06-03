# CMakeList.txt : CMake project for Plantilla_PostFija, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Plantilla_PostFija "Plantilla_PostFija.cpp" "Plantilla_PostFija.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Plantilla_PostFija PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
