#ifndef GML_VECTOR4_H
#define GML_VECTOR4_H

#include <gml/vector/vector3.h>

typedef struct{
  float x;
  float y;
  float z;
  float w;
} gmlVec4;

#define GML_VEC4_TO_PARAMS(vec) vec.x, vec.y, vec.z, vec.w


static float gmlVec4DotProduct(gmlVec4 vec1, gmlVec4 vec2){
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

//Mathematical operations with other 4 component vectors
static gmlVec4 gmlVec4Add(gmlVec4 vec1, gmlVec4 vec2){
  return gmlVec4{vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w};
}

static gmlVec4 gmlVec4Negate(gmlVec4 vec1){
  return gmlVec4{-vec1.x, -vec1.y, -vec1.z, -vec1.w};
}

//Mathematical operations with scalars
static gmlVec4 gmlVec4Addf(gmlVec4 vec1, float f){
  return gmlVec4{vec1.x + f, vec1.y + f, vec1.z + f, vec1.w + f};
}

static gmlVec4 gmlVec4Subractf(gmlVec4 vec1, float f){
  return gmlVec4{vec1.x - f, vec1.y - f, vec1.z - f, vec1.w - f};
}

static gmlVec4 gmlVec4Multiplyf(gmlVec4 vec1, float f){
  return gmlVec4{vec1.x * f, vec1.y * f, vec1.z * f, vec1.w * f};
}

static gmlVec4 gmlVec4Dividef(gmlVec4 vec1, float f){
  return gmlVec4{vec1.x / f, vec1.y / f, vec1.z / f, vec1.w / f};
}

static gmlVec4 gmlVec3To4(gmlVec3* vec){
  return gmlVec4{vec->x, vec->y, vec->z, 1.0f};
}

#endif //GML_VECTOR4_H
