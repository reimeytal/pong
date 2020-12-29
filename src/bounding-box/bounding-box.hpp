#ifndef PONG_BOUNDING_BOX_HPP
#define PONG_BOUNDING_BOX_HPP
#include <gml/gml.hpp>
#include <string>

namespace pong{
  class BoundingBox{
  private:
    gml::vec2 startingPoint;
    gml::vec2 size;

    friend class Ball;
  public:
    BoundingBox(gml::vec2, gml::vec2);

    inline gml::vec2 getStartingPoint() const{
      return startingPoint;
    }

    inline gml::vec2 getSize() const{
      return size;
    }
    bool collides_with(const BoundingBox&) const;

    std::string to_string() const;
  };
}

#endif //PONG_BOUNDING_BOX_HPP
