#include <gml/gml.hpp>
#include "entity.hpp"
#include "../vertex.h"

namespace pong{
  Entity::Entity()
    :modelMatrix(new gml::mat4(GML_COLUMN_MAJOR))
  {
    modelMatrix->make_identity_matrix();
  }

  Entity::~Entity(){
    delete modelMatrix;
  }
}
