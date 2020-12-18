#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../vertex.h"

namespace pong{
  class Entity{
  protected:
    vertex_t* vertices;
  public:
    Entity(int numOfVertices);

    ~Entity();

    virtual void draw() const = 0;
    virtual bool collides_with(const Entity&) const = 0;
  };
}

#endif //ENTITY_HPP
