#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gml/gml.hpp>
#include <iostream>

#include "src/vertex.h"
#include "src/ball/ball.hpp"
#include "src/paddle/paddle.hpp"
#include "src/shader/shader.hpp"

#define PONG_RESOLUTION 1080, 720

static GLFWwindow* window;

int main(){
  if(!glfwInit()){
    return 1;
  }


  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window = glfwCreateWindow(PONG_RESOLUTION, "Pong", NULL, NULL);
  if(!window){
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glewInit();

  glEnable(GL_CULL_FACE);

  pong::Paddle::init();

  pong::Paddle p1 = pong::Paddle();

  gml::mat4 projectionMatrix = gml::orthographic_projection(-8.0f, 8.0f, -4.5f, 4.5f, 0.1f, 100.0f);

  ShaderInfo vsinfo("shaders/vs.glsl", GL_VERTEX_SHADER);
  ShaderInfo fsinfo("shaders/fs.glsl", GL_FRAGMENT_SHADER);

  Shader s(2, &vsinfo, &fsinfo);

  s.bind();

  while(!glfwWindowShouldClose(window)){
      glClear(GL_COLOR_BUFFER_BIT);

      p1.draw(s, projectionMatrix);

      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  pong::Paddle::uninit();

  glfwTerminate();
  return 0;
}
