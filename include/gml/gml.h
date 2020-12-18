#ifndef GML_H
#define GML_H

//GML Strings
//Version 1.0.0
#define GML_VERSION "1.0.0"

//GML cross-language include files
#include <gml/functions/pythagoras.h>
#include <gml/functions/radians.h>

//GML C version include Files
#ifndef __cplusplus
#include <gml/vector/vector3.h>
#include <gml/vector/vector4.h>
#include <gml/functions/projection_functions/orthographic_projection.h>

#include <gml/matrix/matrix4.h>
#endif //__cplusplus

#endif //GML_H
