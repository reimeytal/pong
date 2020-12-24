#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <gml/gml.hpp>
#include "../vertex.h"
#include "../shader/shader.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
  class Entity{
  protected:
    gml::mat4 modelMatrix;
  public:
    Entity();

    virtual void draw(const Shader&, const gml::mat4&) const = 0;
    virtual BoundingBox getBoundingBox() = 0;
    void setPosition(gml::vec3);
  };
}

#endif //ENTITY_HPP
