#include <gl/glew.h>
#include <vector>
#include <cstdint>
#include <cmath>
#include <gml/gml.hpp>

#include "../bounding-box/bounding-box.hpp"
#include "../vertex.h"
#include "ball.hpp"

#define PONG_BALL_NUM_OF_POINTS 30
#define PONG_BALL_RADIUS 0.5f

namespace pong{

  unsigned int Ball::vao      = 0;
  unsigned int Ball::vbo      = 0;
  unsigned int Ball::ibo      = 0;
  unsigned int Ball::ibo_size = 0;

  void Ball::init(){
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER,         vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    vertex_t* vdata = new vertex_t[PONG_BALL_NUM_OF_POINTS + 1];
    std::vector<uint32_t>* idata = new std::vector<uint32_t>();

    vdata[0] = {0.0f, 0.0f};

    for(uint32_t i=1;i<=PONG_BALL_NUM_OF_POINTS;i++){
      vdata[i] = {
        PONG_BALL_RADIUS *  sin(gml::to_radians(360.f/PONG_BALL_NUM_OF_POINTS * i)),
        -PONG_BALL_RADIUS * cos(gml::to_radians(360.f/PONG_BALL_NUM_OF_POINTS * i))
      };

      idata->push_back(0);
      idata->push_back(i);
      if(i != PONG_BALL_NUM_OF_POINTS){
          idata->push_back(i+1);
      } else{
        idata->push_back(1);
      }
    }

    ibo_size = idata->size();

    glBufferData(GL_ARRAY_BUFFER,         sizeof(vertex_t) * (PONG_BALL_NUM_OF_POINTS + 1), vdata,     GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * ibo_size,                  idata->data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), 0);
    glBindVertexArray(0);

    delete[] vdata;
    delete idata;
  }

  void Ball::uninit(){
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
  }

  Ball::Ball(){
    modelMatrix.scale(0.70f, 0.70f, 1.0f);
  }

  void Ball::draw(const Shader& shader, const gml::mat4& projectionMatrix) const{
    shader.bind();
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    shader.bind();

    shader.useUniformMat4f("projectionMatrix", projectionMatrix);
    shader.useUniformMat4f("modelMatrix", modelMatrix);

    glDrawElements(GL_TRIANGLES, ibo_size, GL_UNSIGNED_INT, NULL);

    glBindVertexArray(0);
  }

  BoundingBox Ball::getBoundingBox() {}

}
