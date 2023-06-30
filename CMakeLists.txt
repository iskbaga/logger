cmake_minimum_required(VERSION 3.22)
project(untitled16)

# Inlcude directories
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

# Source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Separate executable: main
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_executable(untitled16 src/main.cpp src/Logger.cpp include/Logger.h src/AbstractLogger.cpp include/AbstractLogger.h include/ErrorLogger.h include/WarningLogger.h include/DebugLogger.h src/WarningLogger.cpp src/ErrorLogger.cpp src/DebugLogger.cpp)
