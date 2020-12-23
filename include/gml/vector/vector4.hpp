#ifndef GML_VECTOR4_HPP
#define GML_VECTOR4_HPP

#include <gml/vector/vector4.h>
#include <gml/vector/vector3.h>
#include <gml/vector/vector3.hpp>

namespace gml{

  class vec4{
  protected:
    inline gmlVec4 to_gmlVec4() const{
      return {this->x, this->y, this->z, this->w};
    }

  public:
    float x;
    float y;
    float z;
    float w;

    vec4(float x, float y, float z, float w=1.0f)
      :x(x), y(y), z(z), w(w) {}

    vec4(float all=0.0f)
      :x(all), y(all), z(all) {}

    vec4(gmlVec4 vec)
      :x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}

    vec4(gmlVec3 vec)
      :x(vec.x), y(vec.y), z(vec.z), w(1.0f) {}

    vec4(vec3 vec)
      :x(vec.x), y(vec.y), z(vec.z), w(1.0f) {}

    inline float dot_product(vec4& otherVec) const{
      return gmlVec4DotProduct(this->to_gmlVec4(), otherVec.to_gmlVec4());
    }

    //Negate vector
    vec4 operator-(){
      return vec4(gmlVec4Negate(this->to_gmlVec4()));
    }

    //Mathematical operations on other 4 component vectors
    vec4 operator+(vec4 otherVec){
      return vec4(gmlVec4Add(this->to_gmlVec4(), otherVec.to_gmlVec4()));
    }

    //Mathematical operations on scalars
    vec4 operator+(float f){
      return vec4(gmlVec4Addf(this->to_gmlVec4(), f));
    }

    vec4 operator-(float f){
      return vec4(gmlVec4Subractf(this->to_gmlVec4(), f));
    }

    vec4 operator*(float f){
      return vec4(gmlVec4Multiplyf(this->to_gmlVec4(), f));
    }

    vec4 operator/(float f){
      return vec4(gmlVec4Dividef(this->to_gmlVec4(), f));
    }
  };

}
#endif //GML_VECTOR4_HPP
