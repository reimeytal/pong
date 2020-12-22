#ifndef GML_VECTOR2_H
#define GML_VECTOR2_H

#define GML_VEC2_TO_PARAMS(vec) vec.x, vec.y

typedef struct{
  float x;
  float y;
} gmlVec2;


static float gmlVec2DotProduct(gmlVec2 vec1, gmlVec2 vec2){
  return vec1.x * vec2.x + vec1.y * vec2.y;
}

//Mathematical operations with other 3 component vectors
static gmlVec2 gmlVec2Add(gmlVec2 vec1, gmlVec2 vec2){
  return gmlVec2{vec1.x + vec2.x, vec1.y + vec2.y};
}

static gmlVec2 gmlVec2Negate(gmlVec2 vec1){
  return gmlVec2{-vec1.x, -vec1.y};
}

//Mathematical operations with scalars
static gmlVec2 gmlVec2Addf(gmlVec2 vec1, float f){
  return gmlVec2{vec1.x + f, vec1.y + f};
}

static gmlVec2 gmlVec2Subractf(gmlVec2 vec1, float f){
  return gmlVec2{vec1.x - f, vec1.y - f};
}

static gmlVec2 gmlVec2Multiplyf(gmlVec2 vec1, float f){
  return gmlVec2{vec1.x * f, vec1.y * f};
}

static gmlVec2 gmlVec2Dividef(gmlVec2 vec1, float f){
  return gmlVec2{vec1.x / f, vec1.y / f};
}

#endif //GML_VECTOR2_H
