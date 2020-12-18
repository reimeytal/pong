#ifndef GML_MATRIX4_HPP
#define GML_MATRIX4_HPP
#include <cstring>
#include <cstdint>

#include <gml/matrix/matrix4.h>
#include <gml/vector/vector3.h>

#include <gml/vector/vector4.hpp>

namespace gml{
  class mat4{
  protected:
    float data[16];
    uint8_t major;
  public:
    mat4() = delete;

    mat4(uint8_t major)
      :major(major)
    {
      memset(data, 0, sizeof(float) * 16);
    }

    inline void make_identity_matrix(){
      gmlIdentityMat4((gmlMat4*)this);
    }

    inline void translate(float x, float y, float z){
      gmlTranslateMat4((gmlMat4*)this, {x, y, z});
    }

    inline void translate(vec3& vec){
      gmlTranslateMat4((gmlMat4*)this, *((gmlVec3*)&vec));
    }

    inline void scale(float x, float y, float z){
      gmlScaleMat4((gmlMat4*)this, {x, y, z});
    }

    inline void scale(vec3& vec){
      gmlScaleMat4((gmlMat4*)this, *((gmlVec3*)&vec));
    }

    inline void rotate(float theta, uint8_t axis){
      gmlRotateMat4((gmlMat4*)this, theta, axis);
    }

    inline void print() const{
      gmlPrintMat4((gmlMat4*)this);
    }

    mat4 operator+(mat4& otherMat){
      mat4 ret(this->major);
      gmlAddMat4((gmlMat4*)this, (gmlMat4*)&otherMat, (gmlMat4*)&ret);
      return ret;
    }

    mat4 operator*(mat4& otherMat){
      mat4 ret(this->major);
      gmlMultiplyMat4((gmlMat4*)this, (gmlMat4*)&otherMat, (gmlMat4*)&ret);
      return ret;
    }

    vec4 operator*(vec4& otherVec){
      return vec4(gmlMultiplyMat4Vec4((gmlMat4*)this, (gmlVec4*)&otherVec));
    }

    float& operator()(uint8_t i, uint8_t j){
      return *(gmlMat4GetElemPointer((gmlMat4*)this, i, j));
    }
  };
}

#endif //GML_MATRIX4_HPP
