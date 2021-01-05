#ifndef BALL_HPP
#define BALL_HPP

#include "../bounding-box/bounding-box.hpp"
#include "../paddle/paddle.hpp"
#include "../vertex.h"
#include "../entity/entity.hpp"

namespace pong{

  class Ball : public Entity{
  private:
    static unsigned int vao, vbo, ibo, ibo_size;
    gml::vec2 direction_vector;
  public:
    static void init();
    static void uninit();

    Ball();

    void draw(const Shader&, const gml::mat4&) const;
    void move(Paddle& p1, Paddle& p2, BoundingBox& top, BoundingBox& bottom);
    void reset();
    BoundingBox getBoundingBox();
  };

}

#endif //BALL_HPP
