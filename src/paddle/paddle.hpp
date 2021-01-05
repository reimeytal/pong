#ifndef PONG_PADDLE_HPP
#define PONG_PADDLE_HPP

#include <gml/gml.hpp>
#include <cstdint>

#include "../shader/shader.hpp"
#include "../vertex.h"
#include "../entity/entity.hpp"

#define PADDLE_UP   1
#define PADDLE_DOWN 2

namespace pong{

  class Paddle : public Entity{
  private:
    static unsigned int vbo, ibo, vao;
  public:
    Paddle();

    static void init();
    static void uninit();

    void draw(const Shader&, const gml::mat4&) const;
    BoundingBox getBoundingBox();
    void move(uint8_t, float);
  };

}


#endif //PADDLE_HPP
