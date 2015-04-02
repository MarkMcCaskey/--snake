CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(--snake)

# Set the search path for cmake modules
# Added FindSDL2.cmake
# Reference: https://github.com/brendanwhitfield/collector/blob/master/cmake/FindSDL2.cmake
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules/)

# Find packages on the target system using cmake modules
FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)
# Include header files found for the package
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# The source file that will be used to emit an exectuable
SET(SOURCE_FILES src/main.cpp)

# Make the executable
ADD_EXECUTABLE(main ${SOURCE_FILES})
# Link the dynamic libraries
TARGET_LINK_LIBRARIES(main ${SDL2_LIBRARY})
TARGET_LINK_LIBRARIES(main ${Boost_LIBRARIES})
# Emit the executable to the bin directory when using: make install
INSTALL(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/bin)
