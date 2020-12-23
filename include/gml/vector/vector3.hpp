#ifndef GML_VECTOR3_HPP
#define GML_VECTOR3_HPP

#include <gml/vector/vector3.h>

namespace gml{

  class vec3{
  protected:
    inline gmlVec3 to_gmlVec3() const{
      return {this->x, this->y, this->z};
    }

  public:
    float x;
    float y;
    float z;

    vec3(float x, float y, float z)
      :x(x), y(y), z(z) {}

    vec3(float all=0.0f)
      :x(all), y(all), z(all) {}

    vec3(gmlVec3 vec)
      :x(vec.x), y(vec.y), z(vec.z) {}

    inline float dot_product(vec3 otherVec) const{
      return gmlVec3DotProduct(this->to_gmlVec3(), otherVec.to_gmlVec3());
    }

    inline vec3 cross_product(vec3 otherVec) const{
      return vec3(gmlVec3CrossProduct(this->to_gmlVec3(), otherVec.to_gmlVec3()));
    }

    //Negate vector
    vec3 operator- (){
      return vec3(gmlVec3Negate(this->to_gmlVec3()));
    }

    //Mathematical operations on other 3 component vectors
    vec3 operator+ (vec3 otherVec){
      return vec3(gmlVec3Add(this->to_gmlVec3(), otherVec.to_gmlVec3()));
    }

    //Mathematical operations on scalars
    vec3 operator+ (float f){
      return vec3(gmlVec3Addf(this->to_gmlVec3(), f));
    }

    vec3 operator- (float f){
      return vec3(gmlVec3Subractf(this->to_gmlVec3(), f));
    }

    vec3 operator* (float f){
      return vec3(gmlVec3Multiplyf(this->to_gmlVec3(), f));
    }

    vec3 operator/ (float f){
      return vec3(gmlVec3Dividef(this->to_gmlVec3(), f));
    }
  };

}

#endif //GML_VECTOR3_HPP
