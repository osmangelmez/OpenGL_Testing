cmake_minimum_required( VERSION 3.5 )

project( planet_sim )

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )


add_subdirectory( glfw )

include_directories( glfw/deps/imgui )

option( OPENGL-PROJ-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

if( OPENGL-PROJ-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad1/gl.h" )
    include_directories("/usr/include/glad)")
    set(GLAD_GL_2 "/usr/include/glad/glad.h")
endif()

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

set( OPENGL-PROJ-SRC
        src/main.cpp
        )
file( GLOB SOURCE_FILES src/*.c src/*.cpp shaders/*.vert shaders/*.frag imgui/*.cpp imgui/*.h)
add_executable( planet_sim ${SOURCE_FILES} src/main.cpp)
target_link_libraries( planet_sim ${OPENGL_LIBRARIES} glfw )

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'planet_sim' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT planet_sim )
    endif()
endif()

