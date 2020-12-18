#ifndef GML_ORTHOGRAPIC_PROJECTION_HPP
#define GML_ORTHOGRAPIC_PROJECTION_HPP

#include <gml/matrix/matrix4.hpp>
#include <gml/matrix/matrix4.h>

#include <gml/functions/projection_functions/orthographic_projection.h>

namespace gml{
  static mat4 orthographic_projection(float left, float right, float bottom, float top, float near, float far, uint8_t return_major=GML_COLUMN_MAJOR){
    mat4 ret(return_major);
    ret.make_identity_matrix();

    gmlOrthographicProjection((gmlMat4*)&ret, left, right, bottom, top, near, far);

    return ret;
  }
}

#endif //GML_ORTHOGRAPIC_PROJECTION_HPP
