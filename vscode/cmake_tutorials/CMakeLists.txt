cmake_minimum_required(VERSION 2.6)
project(Tutorial)

# Should we use our own math functions?
option(USE_MYMATH 
    "Use tutorial provided math implementation" ON)

#Set Version NUmber
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# Configure a header file to pass some of the CMake settings
# to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# Add the MathFunctions library?
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)



# Add the binary tree to the search path for include files
# to the source code

include_directories("${PROJECT_BINARY_DIR}")
add_executable(Tutorial tutorial.c)
target_link_libraries(Tutorial ${EXTRA_LIBS})



# Add the install targets
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    DESTINATION include)