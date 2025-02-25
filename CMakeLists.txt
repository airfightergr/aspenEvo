cmake_minimum_required(VERSION 3.20)
project(aspenEvo VERSION 0.9.0)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all X-Plane SDK APIs up to the newest version.
add_definitions(-DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1 -DXPLM302=1 -DXPLM303=1 -DXPLM400=1 -DXPLM410=1)

if (APPLE)
    #    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.3" CACHE STRING "Minimum macOS version" FORCE)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Build architectures for Mac OS X" FORCE) # We will enable this when we have a SDK supporting arm
    set(ARCH "mac64")
    add_definitions(-DAPL=1 -DIBM=0 -DLIN=0)

elseif (WIN32)
    set(ARCH "mingw64")
    add_definitions(-DAPL=0 -DIBM=1 -DLIN=0)
    add_definitions(-D_WIN32_WINNT=0x0600)

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
    set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS}  -static-libgcc -static-libstdc++ -s")

else ()
    set(ARCH "lin64")
    add_definitions(-DAPL=0 -DIBM=0 -DLIN=1)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused -Wall -Wno-missing-field-initializers -Wshadow -Wextra -Wno-error")
endif ()

# Set up acfutils
option(LIBACFUTILS "${CMAKE_SOURCE_DIR}")

file(GLOB LIBACFUTILS_LIBS libacfutils-redist/${ARCH}/lib/*.a)
if (WIN32)
    list(APPEND LIBACFUTILS_LIBS crypt32 ws2_32 gdi32 dbghelp psapi winmm)
else ()
    list(APPEND LIBACFUTILS_LIBS pthread)
endif ()

set(SDK_ROOT "${CMAKE_SOURCE_DIR}/SDK")

# Set include directories used by our code and dependencies.
include_directories(
        "SDK/CHeaders/Widgets"
        "SDK/CHeaders/Wrappers"
        "SDK/CHeaders/XPLM"
        "libacfutils-redist/include/"
        "libacfutils-redist/${ARCH}/include/"
        "includes/"
)

# Specify library search locations.
if (WIN32)
    list(APPEND CMAKE_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/SDK/Libraries/Win")
#elseif (APPLE)
    list(APPEND CMAKE_FRAMEWORK_PATH "${CMAKE_SOURCE_DIR}/SDK/Libraries/Mac")
#elseif (UNIX)

endif ()

# Set up required libraries
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

add_library(aspenEvo SHARED
            src/main.c            src/main.h
            src/datarefs.c        src/datarefs.h
            src/globals.c         src/globals.h
            src/device.c          src/device.h
            #src/draw_cairo.c      src/draw_cairo.h
)

target_compile_options(aspenEvo PUBLIC -Wall)
target_link_libraries(aspenEvo PUBLIC ${LIBACFUTILS_LIBS} ${OPENGL_LIBRARIES})

# X-Plane XPLM stuff
if (APPLE)
    find_library(XPLM_LIBRARY XPLM ${SDK_ROOT}/Libraries/Mac/)
    find_library(XPWIDGETS_LIBRARY XPWidgets ${SDK_ROOT}/Libraries/Mac/)
    find_library(CocoaLib Cocoa)

    target_link_libraries(kap140_plugin PUBLIC ${XPLM_LIBRARY})
    target_link_libraries(kap140_plugin PUBLIC ${XPWIDGETS_LIBRARY})
    target_link_libraries(kap140_plugin PUBLIC ${CocoaLib})

elseif (WIN32)
    set(CMAKE_LIBRARY_PATH ${SDK_ROOT}/Libraries/Win/)
    find_library(XPLM_LIBRARY
            NAMES XPLM_64
            PATHS ${SDK_ROOT}/Libraries/Win/
            NO_DEFAULT_PATH
            NO_CMAKE_FIND_ROOT_PATH
    )
    #    find_library(XPWIDGETS_LIBRARY
    #            NAMES XPLMWidgets_64
    #            PATHS SDK/Libraries/Win/
    #            NO_DEFAULT_PATH
    #            NO_CMAKE_FIND_ROOT_PATH
    #    )
    target_link_libraries(aspenEvo PUBLIC ${XPLM_LIBRARY} ${XPWIDGETS_LIBRARY})

endif ()

set_target_properties(aspenEvo PROPERTIES LINK_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fno-stack-protector -fPIC -fvisibility=hidden -Wno-unused")

add_compile_options(-fexceptions)
add_compile_options(-fvisibility=hidden)
add_compile_options(-Wall -Wpedantic -Wshadow -Wfloat-equal -Wextra)
add_compile_options(-Wno-unused)


set_target_properties(aspenEvo PROPERTIES PREFIX "")
set_target_properties(aspenEvo PROPERTIES SUFFIX "")
set_target_properties(aspenEvo PROPERTIES SUFFIX ".xpl")  # Enable to build locally, disable before committing
set_target_properties(aspenEvo PROPERTIES OUTPUT_NAME "aspenEvo") # Enable to build locally, disable before committing

if (WIN32)
    set_target_properties(aspenEvo PROPERTIES OUTPUT_NAME "aspenEvo")
    #set_target_properties(aspenEvo PROPERTIES OUTPUT_NAME "win.xpl")
elseif (APPLE)
    set_target_properties(aspenEvo PROPERTIES OUTPUT_NAME "mac.xpl")
elseif (UNIX)
 set_target_properties(aspenEvo PROPERTIES OUTPUT_NAME "lin_x64/aspenEvo")
   # set_target_properties(aspenEvo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PLUGIN_BUILD_DIR}/lin_x64")      # Enable to build locally, disable before committing
  #  set_target_properties(aspenEvo PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PLUGIN_BUILD_DIR}/lin_x64")      # Enable to build locally, disable before committing
endif ()
