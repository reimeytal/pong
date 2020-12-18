#ifndef GML_MATRIX4_H
#define GML_MATRIX4_H

#define GML_ROW_MAJOR    0
#define GML_COLUMN_MAJOR 1

#define GML_X 1
#define GML_Y 2
#define GML_Z 4

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <gml/vector/vector4.h>

typedef struct{
  float data[16];
  uint8_t major;
} gmlMat4;

static void gmlCreateMat4(gmlMat4* mat, uint8_t major){
  if(major > 1){
    return;
  }
  *mat = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, major};
}

static float gmlMat4GetElem(gmlMat4* mat, uint8_t i, uint8_t j){ //row, column
  if(j >= 4 || i >= 4){
    return 0.0f;
  }
  switch(mat->major){
    case GML_ROW_MAJOR:
      return mat->data[i * 4 + j];
    case GML_COLUMN_MAJOR:
      return mat->data[i + j*4];
    default:
      return 0.0f;
  }
}

static float* gmlMat4GetElemPointer(gmlMat4* mat, uint8_t i, uint8_t j){ //row, column
  if(j >= 4 || i >= 4){
    return NULL;
  }
  switch(mat->major){
    case GML_ROW_MAJOR:
      return &mat->data[i * 4 + j];
    case GML_COLUMN_MAJOR:
      return &mat->data[i + j * 4];
    default:
      return NULL;
  }
}

static void gmlMat4SetElem(gmlMat4* mat, uint8_t i, uint8_t j, float value){ //row, column, value
  *(gmlMat4GetElemPointer(mat, i, j)) = value;
}

static gmlVec4 gmlMat4GetRow(gmlMat4* mat, uint8_t i){
  return {gmlMat4GetElem(mat, i, 0), gmlMat4GetElem(mat, i, 1), gmlMat4GetElem(mat, i, 2), gmlMat4GetElem(mat, i, 3)};
}

static gmlVec4 gmlMat4GetColumn(gmlMat4* mat, uint8_t j){
  return {gmlMat4GetElem(mat, 0, j), gmlMat4GetElem(mat, 1, j), gmlMat4GetElem(mat, 2, j), gmlMat4GetElem(mat, 3, j)};
}

static void gmlIdentityMat4(gmlMat4* mat){
  for(uint8_t i=0;i<4;i++){
    gmlMat4SetElem(mat, i, i, 1.0f);
  }
}

static void gmlMat4RowToColumn(gmlMat4* mat){
  if(mat->major == GML_COLUMN_MAJOR){
    return;
  }

  gmlMat4 ret;
  gmlCreateMat4(&ret, GML_COLUMN_MAJOR);

  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(&ret, i, j, gmlMat4GetElem(mat, i, j));
    }
  }
  *mat = ret;
}

static void gmlMat4ColumnToRow(gmlMat4* mat){
  if(mat->major == GML_ROW_MAJOR){
    return;
  }

  gmlMat4 ret;
  gmlCreateMat4(&ret, GML_ROW_MAJOR);

  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(&ret, i, j, gmlMat4GetElem(mat, i, j));
    }
  }
  *mat = ret;
}

static void gmlAddMat4(gmlMat4* mat1, gmlMat4* mat2, gmlMat4* result){
  for(uint8_t i=0;i<4;i++){
    for(uint8_t j=0;j<4;j++){
      gmlMat4SetElem(result, i, j, gmlMat4GetElem(mat1, i, j) + gmlMat4GetElem(mat2, i, j));
    }
  }
}

static void gmlMultiplyMat4(gmlMat4* mat1, gmlMat4* mat2, gmlMat4* result){
  for(uint8_t j=0;j<4;j++){
    for(uint8_t i=0;i<4;i++){
      gmlMat4SetElem(result, i, j, gmlVec4DotProduct(gmlMat4GetRow(mat2, i), gmlMat4GetColumn(mat1, j)));
    }
  }
}

static gmlVec4 gmlMultiplyMat4Vec4(gmlMat4* mat, gmlVec4* vec){
  gmlVec4 ret;
  ret.x = gmlVec4DotProduct(gmlMat4GetRow(mat, 0), *vec);
  ret.y = gmlVec4DotProduct(gmlMat4GetRow(mat, 1), *vec);
  ret.z = gmlVec4DotProduct(gmlMat4GetRow(mat, 2), *vec);
  ret.w = gmlVec4DotProduct(gmlMat4GetRow(mat, 3), *vec);
  return ret;
}

static void gmlPrintMat4(gmlMat4* mat){
  gmlVec4 toPrint;
  for(uint8_t i=0;i<4;i++){
    toPrint = gmlMat4GetRow(mat, i);
    printf("| %10f %10f %10f %10f |\n", GML_VEC4_TO_PARAMS(toPrint));
  }
  fflush(stdout);
}

static void gmlTranslateMat4(gmlMat4* mat, gmlVec3 vec){
  gmlMat4SetElem(mat, 0, 3, gmlMat4GetElem(mat, 0, 3) + vec.x);
  gmlMat4SetElem(mat, 1, 3, gmlMat4GetElem(mat, 1, 3) + vec.y);
  gmlMat4SetElem(mat, 2, 3, gmlMat4GetElem(mat, 2, 3) + vec.z);
}

static void gmlScaleMat4(gmlMat4* mat, gmlVec3 vec){
  gmlMat4SetElem(mat, 0, 0, gmlMat4GetElem(mat, 0, 0) * vec.x);
  gmlMat4SetElem(mat, 1, 1, gmlMat4GetElem(mat, 1, 1) * vec.y);
  gmlMat4SetElem(mat, 2, 2, gmlMat4GetElem(mat, 2, 2) * vec.z);
}

static void gmlRotateMat4(gmlMat4* mat, float theta, uint8_t axis){
  gmlMat4 rotationMat, result;

  gmlCreateMat4(&result, mat->major);

  gmlCreateMat4(&rotationMat, GML_COLUMN_MAJOR);
  gmlIdentityMat4(&rotationMat);

  if((axis & 0b1) == GML_X){
    gmlMat4SetElem(&rotationMat, 1, 1,    cos(theta));
    gmlMat4SetElem(&rotationMat, 1, 2, -1*sin(theta));
    gmlMat4SetElem(&rotationMat, 2, 1,    sin(theta));
    gmlMat4SetElem(&rotationMat, 2, 2,    cos(theta));
  }

  if((axis & 0b10) == GML_Y){
    gmlMat4SetElem(&rotationMat, 0, 0,    cos(theta));
    gmlMat4SetElem(&rotationMat, 0, 2,    sin(theta));
    gmlMat4SetElem(&rotationMat, 2, 0, -1*sin(theta));
    gmlMat4SetElem(&rotationMat, 2, 2,    cos(theta));
  }

  if((axis & 0b100) == GML_Z){
    gmlMat4SetElem(&rotationMat, 0, 0,    cos(theta));
    gmlMat4SetElem(&rotationMat, 1, 0,    sin(theta));
    gmlMat4SetElem(&rotationMat, 0, 1, -1*sin(theta));
    gmlMat4SetElem(&rotationMat, 1, 1,    cos(theta));
  }

  gmlMultiplyMat4(mat, &rotationMat, &result);
  *mat = result;
}

#endif //GML_MATRIX4_H
