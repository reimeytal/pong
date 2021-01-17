#include <GL/glew.h>
#include <gml/gml.hpp>
#include <stb_image.h>

#include <string>
#include <cstdint>

#include "score.hpp"
#include "../vertex.h"
#include "../shader/shader.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
  unsigned int Score::vao;
  unsigned int Score::vbo;
  unsigned int Score::ibo;
  unsigned int Score::nextID = 0;
  unsigned int Score::textures[12];

  void Score::init(){
    glGenVertexArrays(1, &vao);
    glGenBuffers     (2, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,         vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    textureVertex_t vertices[4] = {
      {-4.0f,  4.0f, -1.0f,  1.0f},
      { 4.0f,  4.0f,  1.0f,  1.0f},
      { 4.0f, -4.0f,  1.0f, -1.0f},
      {-4.0f, -4.0f, -1.0f, -1.0f}
    };

    unsigned int indices[6] = {
      0, 3, 2,
      2, 1, 0
    };

    glBufferData(GL_ARRAY_BUFFER,         sizeof(textureVertex_t)*4, vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*6,    indices,  GL_STATIC_DRAW);

    glGenTextures(12, textures);
    stbi_set_flip_vertically_on_load(1);

    int width, height;

    for(uint8_t i=0;i<12;i++){
      glBindTexture(GL_TEXTURE_2D, textures[i]);
      uint8_t* textureData = stbi_load(std::string("./textures/"+std::to_string(i)+".png").c_str(), &width, &height, nullptr, 4);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);

      stbi_image_free(textureData);
    }

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(textureVertex_t), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(textureVertex_t), (const void*)offsetof(textureVertex_t, textureX));

    glBindVertexArray(0);
  }

  Score::Score(gml::vec3 scaleVec, gml::vec3 positionVec)
  :scoreID(Score::nextID) {
    glActiveTexture(GL_TEXTURE0+scoreID);
    glBindTexture(GL_TEXTURE_2D, textures[0]);

    modelMatrix.scale(scaleVec);
    modelMatrix.translate(positionVec);
    Score::nextID++;
  }

  void Score::setScore(unsigned int score){
    if(score > 11){
      return;
    }
    glActiveTexture(GL_TEXTURE0 + scoreID);
    glBindTexture(GL_TEXTURE_2D, Score::textures[score]);
  }

  void Score::draw(const Shader& s, const gml::mat4& projectionMatrix) const{
    s.bind();
    glBindVertexArray(Score::vao);

    s.useUniformMat4f("projectionMatrix", projectionMatrix);
    s.useUniformMat4f("modelMatrix",      modelMatrix);
    s.useUniform1i   ("scoreTexture",     scoreID);

    glBindBuffer(GL_ARRAY_BUFFER,         Score::vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Score::ibo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);
  }

  BoundingBox Score::getBoundingBox(){
    return BoundingBox(gml::vec2(0.f, 0.f), gml::vec2(0.f, 0.f));
  }

  void Score::uninit(){
    glDeleteTextures(12, textures);
    glDeleteBuffers(2, &vbo);
    glDeleteVertexArrays(1, &vao);
  }
}
