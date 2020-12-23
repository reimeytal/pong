#ifndef GML_VECTOR2_HPP
#define GML_VECTOR2_HPP

#include <gml/vector/vector2.h>

namespace gml{

  class vec2{
  protected:
    inline gmlVec2 to_gmlVec2() const{
      return {this->x, this->y};
    }

  public:
    float x;
    float y;

    vec2(float x, float y)
      :x(x), y(y) {}

    vec2(float all=0.0f)
      :x(all), y(all) {}

    vec2(gmlVec2 vec)
      :x(vec.x), y(vec.y) {}

    inline float dot_product(vec2 otherVec) const{
      return gmlVec2DotProduct(this->to_gmlVec2(), otherVec.to_gmlVec2());
    }

    //Negate vector
    vec2 operator- (){
      return vec2(gmlVec2Negate(this->to_gmlVec2()));
    }

    //Mathematical operations on other 2 component vectors
    vec2 operator+ (vec2 otherVec){
      return vec2(gmlVec2Add(this->to_gmlVec2(), otherVec.to_gmlVec2()));
    }

    //Mathematical operations on scalars
    vec2 operator+ (float f){
      return vec2(gmlVec2Addf(this->to_gmlVec2(), f));
    }

    vec2 operator- (float f){
      return vec2(gmlVec2Subractf(this->to_gmlVec2(), f));
    }

    vec2 operator* (float f){
      return vec2(gmlVec2Multiplyf(this->to_gmlVec2(), f));
    }

    vec2 operator/ (float f){
      return vec2(gmlVec2Dividef(this->to_gmlVec2(), f));
    }
  };

}

#endif //GML_VECTOR2_HPP
