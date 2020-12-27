#ifndef BALL_HPP
#define BALL_HPP

#include "../bounding-box/bounding-box.hpp"
#include "../vertex.h"
#include "../entity/entity.hpp"

namespace pong{

  class Ball : public Entity{
  private:
    static unsigned int vao, vbo, ibo, ibo_size;
  public:
    static void init();
    static void uninit();

    Ball();

    void draw(const Shader&, const gml::mat4&) const;
    BoundingBox getBoundingBox();
  };

}

#endif //BALL_HPP
