set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")