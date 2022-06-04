cmake_minimum_required(VERSION 3.0.0)
project(GLSnake VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(CTest)
enable_testing()

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include/
)

if (EXISTS ${CMAKE_SOURCE_DIR}/lib)
	LINK_DIRECTORIES(
		${CMAKE_SOURCE_DIR}/lib/
	)
endif()

add_executable(GLSnake
            ${CMAKE_SOURCE_DIR}/include/macros.hpp
            ${CMAKE_SOURCE_DIR}/include/vars.hpp
            ${CMAKE_SOURCE_DIR}/src/main.cpp
            ${CMAKE_SOURCE_DIR}/include/Food.hpp
            ${CMAKE_SOURCE_DIR}/src/Food.cpp
            ${CMAKE_SOURCE_DIR}/include/Snake.hpp
            ${CMAKE_SOURCE_DIR}/src/Snake.cpp
            ${CMAKE_SOURCE_DIR}/include/utils.hpp
            ${CMAKE_SOURCE_DIR}/src/utils.cpp
            ${CMAKE_SOURCE_DIR}/app.rc
)

target_link_libraries(GLSnake
    freeglut
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)