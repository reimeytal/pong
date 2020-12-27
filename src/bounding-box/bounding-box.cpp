#include <gml/gml.hpp>
#include "bounding-box.hpp"

namespace pong{
  BoundingBox::BoundingBox(gml::vec2 startingPoint, gml::vec2 size)
    :startingPoint(startingPoint), size(size) {}

  bool BoundingBox::collides_with(const BoundingBox& other) const{
      return this->startingPoint.x + this->size.x      >= other.getStartingPoint().x &&
      other.getStartingPoint().x   + other.getSize().x >= this->startingPoint.x      &&
      this->startingPoint.y        + this->size.y      >= other.getStartingPoint().y &&
      other.getStartingPoint().y   + other.getSize().y >= this->startingPoint.y;
  }
}
