#ifndef GML_PYTHAGORAS_HPP
#define GML_PYTHAGORAS_HPP

#ifdef __cplusplus
#include <cmath>
namespace gml{
#else
#include <math.h>
#endif //__cplusplus

#ifdef __cplusplus
static float pythagoras(float x, float y){
#else
static float gmlPythagoras(float x, float y){
#endif //__cplusplus
  return sqrt(x*x + y*y);
}

#ifdef __cplusplus
static float reverse_pythagoras(float hypotenuse, float leg){
#else
static float gmlReversePythagoras(float hypotenuse, float leg){
#endif //__cplusplus
  return sqrt(hypotenuse*hypotenuse - leg*leg);
}

#ifdef __cplusplus
} //namespace gml
#endif //__cplusplus
#endif //GML_PYTHAGORAS_HPP
