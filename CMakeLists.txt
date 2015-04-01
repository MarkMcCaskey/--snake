CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(main)

FIND_PACKAGE(Boost 1.40 COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ADD_EXECUTABLE(main src/main.cpp)
TARGET_LINK_LIBRARIES(main ${BOOST_LIBRARIES})
INSTALL(TARGETS main DESTINATION bin)