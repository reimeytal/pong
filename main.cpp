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

void move(pong::Paddle& p1, pong::Paddle& p2){
  //p1 movement
  if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
    p1.move(PADDLE_DOWN);
  } else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
    p1.move(PADDLE_DOWN);
  }
  
  if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
    p1.move(PADDLE_UP);
  } else if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
    p1.move(PADDLE_UP);
  }

  //p2 movement
  if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
    p2.move(PADDLE_DOWN);
  } else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
    p2.move(PADDLE_DOWN);
  }

  if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
    p2.move(PADDLE_UP);
  } else if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
    p2.move(PADDLE_UP);
  }
}

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
  pong::Paddle p2 = pong::Paddle();

  p1.setPosition(gml::vec3(-7.25f, 0.0f, 0.0f));
  p2.setPosition(gml::vec3( 7.25f, 0.0f, 0.0f));

  gml::mat4 projectionMatrix = gml::orthographic_projection(-8.0f, 8.0f, -4.5f, 4.5f, 0.1f, 100.0f);

  ShaderInfo vsinfo("shaders/vs.glsl", GL_VERTEX_SHADER);
  ShaderInfo fsinfo("shaders/fs.glsl", GL_FRAGMENT_SHADER);

  Shader s(2, &vsinfo, &fsinfo);

  s.bind();

  while(!glfwWindowShouldClose(window)){
      glClear(GL_COLOR_BUFFER_BIT);

      p1.draw(s, projectionMatrix);
      p2.draw(s, projectionMatrix);

      move(p1, p2);

      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  pong::Paddle::uninit();

  glfwTerminate();
  return 0;
}
