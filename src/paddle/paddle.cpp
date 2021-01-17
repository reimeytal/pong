#include <gml/gml.hpp>
#include <gl/glew.h>
#include <cstdint>

#include "../shader/shader.hpp"
#include "../vertex.h"
#include "../entity/entity.hpp"
#include "../bounding-box/bounding-box.hpp"
#include "paddle.hpp"

#define PONG_PADDLE_SPEED 7.f

unsigned int pong::Paddle::vbo = 0;
unsigned int pong::Paddle::ibo = 0;
unsigned int pong::Paddle::vao = 0;

namespace pong{
  void Paddle::init(){
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    vertex_t paddleVertices[4] = {
      {-1.0f,  4.5f},
      { 1.0f,  4.5f},
      { 1.0f, -4.5f},
      {-1.0f, -4.5f}
    };

    unsigned int paddleIndices[6] = {
      1, 3, 2,
      0, 3, 1
    };

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ARRAY_BUFFER,         vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBufferData(GL_ARRAY_BUFFER,         sizeof(vertex_t)*4,     paddleVertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*6, paddleIndices,  GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), 0);

    glBindVertexArray(0);
  }

  Paddle::Paddle(){
    modelMatrix.scale(0.175f, 0.175f, 1.0f);
  }

  void Paddle::draw(const Shader& shader, const gml::mat4& projectionMatrix) const{
    glBindVertexArray(Paddle::vao);

    glBindBuffer(GL_ARRAY_BUFFER, Paddle::vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Paddle::ibo);

    shader.bind();

    shader.useUniformMat4f("projectionMatrix", projectionMatrix);
    shader.useUniformMat4f("modelMatrix", modelMatrix);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

    glBindVertexArray(0);
  }

  BoundingBox Paddle::getBoundingBox(){
    gml::vec4 bl   = modelMatrix * gml::vec4(-1.0f, -4.5f, 0.0f, 1.0f); //bottom left corner
    gml::vec4 size = gml::vec4(2.0f * modelMatrix(0, 0), 9.0f * modelMatrix(1, 1), 0.0f, 1.0f);

    return BoundingBox(gml::vec2(bl.x, bl.y), gml::vec2(size.x, size.y)); //size is the bottom left corner
  }

  void Paddle::move(uint8_t moveDirection, float deltatime){
    switch(moveDirection){
      case PADDLE_UP:
        modelMatrix.translate(0.0f,  PONG_PADDLE_SPEED * deltatime, 0.0f);
        break;
      case PADDLE_DOWN:
        modelMatrix.translate(0.0f, -PONG_PADDLE_SPEED * deltatime, 0.0f);
        break;
    }
  }

  void Paddle::uninit(){
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
  }
}
