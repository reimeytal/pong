#ifndef PONG_PADDLE_HPP
#define PONG_PADDLE_HPP

#include <gml/gml.hpp>

#include "../shader/shader.hpp"
#include "../vertex.h"
#include "../entity/entity.hpp"

namespace pong{

  class Paddle : public Entity{
  private:
    static unsigned int vbo, ibo, vao;
  public:
    Paddle();

    static void init();
    static void uninit();

    void draw(const Shader&, const gml::mat4&) const;
    BoundingBox getBoundingBox() const;
  };

}


#endif //PADDLE_HPP
