#ifndef GML_VECTOR3_H
#define GML_VECTOR3_H

#define GML_VEC3_TO_PARAMS(vec) vec.x, vec.y, vec.z

typedef struct{
  float x;
  float y;
  float z;
} gmlVec3;


static float gmlVec3DotProduct(gmlVec3 vec1, gmlVec3 vec2){
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

static gmlVec3 gmlVec3CrossProduct(gmlVec3 vec1, gmlVec3 vec2){
  return gmlVec3{vec1.y * vec2.z - vec1.z * vec2.y,
                 vec1.z * vec2.x - vec1.x * vec2.z,
                 vec1.x * vec2.y - vec1.y * vec2.x};
}

//Mathematical operations with other 3 component vectors
static gmlVec3 gmlVec3Add(gmlVec3 vec1, gmlVec3 vec2){
  return gmlVec3{vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
}

static gmlVec3 gmlVec3Negate(gmlVec3 vec1){
  return gmlVec3{-vec1.x, -vec1.y, -vec1.z};
}

//Mathematical operations with scalars
static gmlVec3 gmlVec3Addf(gmlVec3 vec1, float f){
  return gmlVec3{vec1.x + f, vec1.y + f, vec1.z + f};
}

static gmlVec3 gmlVec3Subractf(gmlVec3 vec1, float f){
  return gmlVec3{vec1.x - f, vec1.y - f, vec1.z - f};
}

static gmlVec3 gmlVec3Multiplyf(gmlVec3 vec1, float f){
  return gmlVec3{vec1.x * f, vec1.y * f, vec1.z * f};
}

static gmlVec3 gmlVec3Dividef(gmlVec3 vec1, float f){
  return gmlVec3{vec1.x / f, vec1.y / f, vec1.z / f};
}

#endif //GML_VECTOR3_H
