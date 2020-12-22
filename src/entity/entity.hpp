#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <gml/gml.hpp>
#include "../vertex.h"
#include "../shader/shader.hpp"

namespace pong{
  struct BoundingBox{
    gml::vec2 startingPoint;
    gml::vec2 size;
  };

  class Entity{
  protected:
    gml::mat4* modelMatrix;
  public:
    Entity();
    ~Entity();

    virtual void draw(const Shader&, const gml::mat4&) const = 0;
    //virtual BoundingBox getBoundingBox() const = 0;
    //bool collides_with(const Entity&) const;
  };
}

#endif //ENTITY_HPP
