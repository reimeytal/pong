#ifndef GML_ORTHOGRAPHIC_PROJECTION_H
#define GML_ORTHOGRAPHIC_PROJECTION_H

#include <gml/matrix/matrix4.h>

static void gmlOrthographicProjection(gmlMat4* mat, float left, float right, float bottom, float top, float near, float far){
  gmlMat4SetElem(mat, 0, 0,  2/(right-left));
  gmlMat4SetElem(mat, 1, 1,  2/(top-bottom));
  gmlMat4SetElem(mat, 2, 2, -2/(far-near));

  gmlMat4SetElem(mat, 3, 0, -1*((right+left)/(right-left)));
  gmlMat4SetElem(mat, 3, 1, -1*((top+bottom)/(top-bottom)));
  gmlMat4SetElem(mat, 3, 2, -1*((far+near)/(far-near)));
}

#endif //GML_ORTHOGRAPHIC_PROJECTION_H
