#ifndef PONG_SHADER_HPP
#define PONG_SHADER_HPP

#include <GL/glew.h>
#include <cstdarg>
#include <string>
#include <gml/gml.hpp>

struct ShaderInfo{
  const char* filename;
  GLenum type;

  ShaderInfo(std::string filename, GLenum type);
};

class Shader{
private:
  unsigned int program;
public:
  Shader(unsigned int numOfShaders, ...);
  ~Shader();
  void bind() const;
  void unbind() const;
  void useUniform1i(const char* name, int x) const;
  void useUniform4f(const char* name, float x, float y, float z=0, float w=1) const;
  void useUniformMat4f(const char* name, const gml::mat4& matrix) const;

  Shader(const Shader& s) = delete;
};

#endif //PONG_SHADER_HPP
