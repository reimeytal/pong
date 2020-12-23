#include <gml/gml.hpp>
#include "bounding-box.hpp"

namespace pong{
  BoundingBox::BoundingBox(gml::vec2 startingPoint, gml::vec2 size)
    :startingPoint(startingPoint), size(size) {}
}
