#------------------------------------------------------------------------------
# Create Main Execute
#------------------------------------------------------------------------------
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Shader.cpp
  COMMAND convert ${PROJECT_SOURCE_DIR}/shader/vertex.shader ${PROJECT_SOURCE_DIR}/shader/fragment.shader
  DEPENDS ../shader/vertex.shader ../shader/fragment.shader ../script/ShaderConverter.cpp
  COMMENT "create shader file")

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(sample main.cpp GLFWException.cpp GLFWManager.cpp GLWindow.cpp Scene.cpp ${CMAKE_CURRENT_BINARY_DIR}/Shader.cpp ShaderProgram.cpp NormalShaderProgram.cpp BoardElement.cpp)
target_link_libraries(sample glfw glad glm)

