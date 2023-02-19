## ========================================================================== ##
##                                SOURCE FILES                                ##
## ========================================================================== ##
configure_file(${PROJECT_SOURCE_DIR}/cmake/version.cpp.in ${CMAKE_SOURCE_DIR}/src/version.cpp)

file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE HEADER_FILES
    "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

# Detemine whether to build as a static or shared library
if (${SAIL_BUILD_SHARED_LIBS})
    add_library(sail SHARED ${SOURCE_FILES})
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    add_library(sail STATIC ${SOURCE_FILES})
endif(${SAIL_BUILD_SHARED_LIBS})

set_target_properties(sail PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Setup include directories
target_include_directories(sail 
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

## ========================================================================== ##
##                                   Install                                  ##
## ========================================================================== ##
include(GNUInstallDirs)

install(TARGETS sail
    EXPORT sail-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/sail/lib
)

# Install include files
install(FILES ${HEADER_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/sail/include/sail)