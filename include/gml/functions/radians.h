#ifndef GML_RADIANS_HPP
#define GML_RADIANS_HPP

// 1 radian = 57.2958 degrees

#ifdef __cplusplus
namespace gml {

static float to_radians(float degrees){
#else
static float gmlToRadians(float degrees){
#endif //__cplusplus
  return degrees/57.2958f;
}

#ifdef __cplusplus
static float to_degrees(float radians){
#else
static float gmlToDegrees(float radians){
#endif //__cplusplus
  return radians*57.2958f;
}

#ifdef __cplusplus
} //namespace gml
#endif //__cplusplus
#endif //GML_RADIANS_HPP
