cmake_minimum_required(VERSION 3.16)
project(CircularWars)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/header
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib
)

# Source files
file(GLOB SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create executable
add_executable(circular_wars ${SOURCES})

# Link libraries
target_link_libraries(circular_wars
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib/libraylib.a
    m pthread dl
)

# Platform-specific libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(circular_wars X11)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(circular_wars opengl32 gdi32 winmm)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")  # macOS
    target_link_libraries(circular_wars
        "-framework CoreVideo"
        "-framework IOKit"
        "-framework Cocoa"
        "-framework GLUT"
        "-framework OpenGL"
    )
endif()

# Set output directory
set_target_properties(circular_wars PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/app
)