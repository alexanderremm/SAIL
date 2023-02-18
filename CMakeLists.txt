cmake_minimum_required(VERSION 3.12)

## ========================================================================== ##
##                                    SAIL                                    ##
## ========================================================================== ##
project(
    SAIL
    VERSION 0.1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_DEBUG_POSTFIX _d)

## ========================================================================== ##
##                                   Options                                  ##
## ========================================================================== ##
option(SAIL_BUILD_DOCS        "Build documentation."        ON)
option(SAIL_BUILD_EXAMPLES    "Build the example programs." ON)
option(SAIL_BUILD_TESTS       "Build the unit tests."       ON)
option(SAIL_BUILD_SHARED_LIBS "Build the shared library."   OFF)

# Build the library
add_subdirectory(src)

# Build documentation
if (${SAIL_BUILD_DOCS})
    include(cmake/build-docs.cmake)
endif(${SAIL_BUILD_DOCS})

# Build examples
if (${SAIL_BUILD_EXAMPLES})
    add_subdirectory(example)
endif(${SAIL_BUILD_EXAMPLES})

# Build tests
if (${SAIL_BUILD_TESTS})
    add_subdirectory(test)
endif(${SAIL_BUILD_TESTS})


## ========================================================================== ##
##                                   Install                                  ##
## ========================================================================== ##
install(EXPORT sail-targets
    FILE sail-targets.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/sail/share/cmake/sail
)

include(CMakePackageConfigHelpers)
# Generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sail-config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/sail-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/sail/share/cmake/sail
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/sail-config-version.cmake"
    VERSION "${sail_VERSION_MAJOR}.${sail_VERSION_MINOR}.${sail_VERSION_PATCH}"
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/sail-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/sail-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/sail/share/cmake/sail
)

export(EXPORT sail-targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/sail-targets.cmake"
)