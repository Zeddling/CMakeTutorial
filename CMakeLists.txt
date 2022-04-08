cmake_minimum_required(VERSION 3.22.3)

project(HelloWorld)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)

#   Download all the submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    #   update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message((STATUS "Submodule update"))
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR
                        RESULT_VARIABLE GIT_SUBMOD_RESULT})
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif(NOT GIT_SUBMOD_RESULT EQUAL "0")
    endif(GIT_SUBMODULE)
endif(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")

#   Check all the submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please check GIT_SUBBMODULE status.")
endif(NOT EXISTS "${PROJECT_SOURCE_DIR}/external_modules/glfw/CMakeLists.txt")


add_subdirectory(external/glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} 
    adder 
    OpenGL::GL
    glfw
)

