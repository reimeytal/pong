#include <gml/gml.hpp>
#include "entity.hpp"
#include "../vertex.h"

namespace pong{
  Entity::Entity()
    :modelMatrix(gml::mat4(GML_COLUMN_MAJOR))
  {
    modelMatrix.make_identity_matrix();
  }

  void Entity::setPosition(gml::vec3 pos){
    modelMatrix(0, 3) = pos.x;
    modelMatrix(1, 3) = pos.y;
    modelMatrix(2, 3) = pos.z;
  }
}
