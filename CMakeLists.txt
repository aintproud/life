cmake_minimum_required(VERSION 3.0)

project(YourProjectName)

set(SOURCES
    src/index.c
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})