#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gml/gml.hpp>

#include "src/vertex.h"
#include "src/ball/ball.hpp"
#include "src/paddle/paddle.hpp"
#include "src/shader/shader.hpp"
#include "src/player/player.hpp"

#define PONG_RESOLUTION 1080, 720

static GLFWwindow* window;

void move(pong::Paddle& p1, pong::Paddle& p2, pong::BoundingBox& top, pong::BoundingBox& bottom){
  //p1 movement
  if(!p1.getBoundingBox().collides_with(bottom)){
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
      p1.move(PADDLE_DOWN);
    } else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
      p1.move(PADDLE_DOWN);
    }
  }

  if(!p1.getBoundingBox().collides_with(top)){
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
      p1.move(PADDLE_UP);
    } else if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
      p1.move(PADDLE_UP);
    }
  }

  //p2 movement
  if(!p2.getBoundingBox().collides_with(bottom)){
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
      p2.move(PADDLE_DOWN);
    } else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
      p2.move(PADDLE_DOWN);
    }
  }

  if(!p2.getBoundingBox().collides_with(top)){
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
      p2.move(PADDLE_UP);
    } else if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
      p2.move(PADDLE_UP);
    }
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
  pong::Ball::init();

  pong::Player p1 = pong::Player(gml::vec3(-7.25f, 0.0f, 0.0f), pong::BoundingBox(gml::vec2( 7.25f, -4.5f), gml::vec2(1.0f, 9.0f)));
  pong::Player p2 = pong::Player(gml::vec3( 7.25f, 0.0f, 0.0f), pong::BoundingBox(gml::vec2(-8.25f, -4.5f), gml::vec2(1.0f, 9.0f)));

  pong::Ball ball = pong::Ball();

  pong::BoundingBox top    = pong::BoundingBox(gml::vec2(-8.0f,  4.5f), gml::vec2(16.0f, 1.0f));
  pong::BoundingBox bottom = pong::BoundingBox(gml::vec2(-8.0f, -5.5f), gml::vec2(16.0f, 1.0f));

  gml::mat4 projectionMatrix = gml::orthographic_projection(-8.0f, 8.0f, -4.5f, 4.5f, 0.1f, 100.0f);

  ShaderInfo vsinfo("shaders/vs.glsl", GL_VERTEX_SHADER);
  ShaderInfo fsinfo("shaders/fs.glsl", GL_FRAGMENT_SHADER);

  Shader s(2, &vsinfo, &fsinfo);

  s.bind();

  while(!glfwWindowShouldClose(window)){
      glClear(GL_COLOR_BUFFER_BIT);

      p1.paddle.draw(s, projectionMatrix);
      p2.paddle.draw(s, projectionMatrix);
      ball.draw     (s, projectionMatrix);

      ball.move(p1.paddle, p2.paddle, top, bottom);
      move     (p1.paddle, p2.paddle, top, bottom);

      p1.checkGoal(ball);
      p2.checkGoal(ball);

      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  pong::Paddle::uninit();
  pong::Ball::uninit();

  glfwTerminate();
  return 0;
}
