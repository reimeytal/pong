#include "entity.hpp"
#include "../vertex.h"

namespace pong{
  Entity::Entity(int numOfVertices){
    vertices = new vertex_t[numOfVertices];
  }

  Entity::~Entity(){
    delete[] vertices;
  }
}
