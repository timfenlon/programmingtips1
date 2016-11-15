CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# about this project
# -------------------
PROJECT( linkedlist1 )
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)")

# set env
# -----------------
#ADD_DEFINITIONS( -DDEF_CON_1 )
# Windows has a different header
if(WIN32)
elseif(UNIX)#Linux
else()
endif()

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/external/lib 
                 ${PROJECT_SOURCE_DIR}/lib)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/includes)

SET(PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}/../bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

#SET(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR})
#SET(CMAKE_CURRENT_BINARY_DIR ${PROJECT_BINARY_DIR})
#SET(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR})

MESSAGE ("Binary Tree Path: ${PROJECT_BINARY_DIR}")

# Add Subfolders
# ----------------------
ADD_SUBDIRECTORY ( src )

#Helper to display current directories for CMAKE project
include(CMakeMessages.cmake)
