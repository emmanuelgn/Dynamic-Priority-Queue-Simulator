cmake_minimum_required(VERSION 3.10)
project(PriorityQueueSimulator)

set(CMAKE_CXX_STANDARD 17)  # Usando C++17 como padrão

# Search for all .cpp files in the src/queue folder
file(GLOB QUEUE_SOURCES "src/queue/*.cpp")

# Adds the executable with all the found files
add_executable(PriorityQueueSimulator
    src/main.cpp
    ${QUEUE_SOURCES}
)