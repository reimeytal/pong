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

  window = glfwCreateWindow(PONG_RESOLUTION, "Pong", NULL, NULL);
  if(!window){
    return 1;
  }

  glfwMakeContextCurrent(window);
  //glfwSwapInterval(1);

  glewInit();

  unsigned int bo[2];

  glGenBuffers(2, bo);
  glBindBuffer(GL_ARRAY_BUFFER, bo[0]);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo[1]);

  vertex_t vertices[3] = {
    { 0.0f,  1.0f},
    {-0.5f, -1.0f},
    { 0.5f, -1.0f},
  };

  unsigned int indices[3] = {
    0, 1, 2
  };

  glBufferData(GL_ARRAY_BUFFER,         3*sizeof(vertex_t),     vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*sizeof(unsigned int), indices,  GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), 0);

  while(!glfwWindowShouldClose(window)){
      glClear(GL_COLOR_BUFFER_BIT);

      glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
