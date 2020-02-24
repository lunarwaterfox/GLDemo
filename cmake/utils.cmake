# import GLFW3

function(import_glfw)
    include(FetchContent)

    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.3.1
    )

    FetchContent_GetProperties(glfw)

    if(NOT glfw_POPULATED)
        FetchContent_Populate(glfw)
        add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
    endif()
endfunction()

# import GLM

function(import_glm)
    include(FetchContent)

    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        0.9.9.7
    )

    FetchContent_GetProperties(glm)

    if(NOT glm_POPULATED)
        FetchContent_Populate(glm)
        add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
        include_directories(${glm_SOURCE_DIR})
    endif()
endfunction()
