# Specify the minimum version.
cmake_minimum_required(VERSION 3.22)

# Specify the project info.
project(
logc4
VERSION 0.1.0
DESCRIPTION "A lightweight logger for the C language."
LANGUAGES C
)

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    src/logc4.c
    src/logc4.h
)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/cmake")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/cmake")

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "src/logc4.h")

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)

# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Create the pkg-config file from the template.
configure_file(src/${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

# Set pkg-config file to install.
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
