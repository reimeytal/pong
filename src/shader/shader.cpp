#include <GL/glew.h>
#include <gml/gml.hpp>

#include <cstdarg>
#include <iostream>
#include "shader.hpp"

static const char* fileToString(const char* filename){
  FILE* file = fopen(filename, "rb");

  fseek(file, 0, SEEK_END);
  size_t filesize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char* ret = (char*) malloc(sizeof(char)*filesize + 1);
  fread(ret, filesize, 1, file);
  fclose(file);
  ret[filesize] = '\0';
  return ret;
}

ShaderInfo::ShaderInfo(std::string filename, GLenum type)
  :filename(filename.c_str()), type(type) {}

Shader::Shader(unsigned int numOfShaders, ...)
  :program(glCreateProgram())
{
  va_list args;
  va_start(args, numOfShaders);
  int result;

  unsigned int shaders[numOfShaders];

  for(unsigned int i=0;i<numOfShaders;i++){
    ShaderInfo* cur_shader = va_arg(args, ShaderInfo*);

    shaders[i] = glCreateShader(cur_shader->type);

    const char* code = fileToString(cur_shader->filename);
    glShaderSource(shaders[i], 1, &code, NULL);
    free((void*)code);

    glCompileShader(shaders[i]);

    glGetShaderiv(shaders[i], GL_COMPILE_STATUS, &result);
    if(!result){
      std::cout<<"Problem with ";
      switch(cur_shader->type){
        case GL_VERTEX_SHADER:
          std::cout<<"GL_VERTEX_SHADER";
          break;
        case GL_FRAGMENT_SHADER:
          std::cout<<"GL_FRAGMENT_SHADER";
          break;
        default:
          std::cout<<cur_shader->type;
      }
      std::cout<<" compilation"<<std::endl;

      glGetShaderiv(shaders[i], GL_INFO_LOG_LENGTH, &result);
      char* infolog = (char*) malloc(sizeof(char)*result);
      glGetShaderInfoLog(shaders[i], result, &result, infolog);
      std::cout<<infolog<<std::endl;

      free(infolog);
      glDeleteShader(shaders[i]);
      shaders[i] = 0;
    }
    glAttachShader(program, shaders[i]);
  }

  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &result);
  if(!result){
    std::cout<<"Problem with program linkage"<<std::endl;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &result);
    char* infolog = (char*)malloc(result*sizeof(char));
    glGetProgramInfoLog(program, result, &result, infolog);
    std::cout<<"Linker InfoLog: "<<infolog<<std::endl;
    free(infolog);

    for(unsigned int i=0;i<numOfShaders;i++){
      glDetachShader(program, shaders[i]);
      glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
  }
  glValidateProgram(program);

  for(unsigned int i=0;i<numOfShaders;i++){
    glDetachShader(program, shaders[i]);
    glDeleteShader(shaders[i]);
  }

  va_end(args);
}

void Shader::useUniform4f(const char* name, float x, float y, float z, float w) const{
  glUniform4f(glGetUniformLocation(program, name), x, y, z, w);
}

void Shader::useUniform1i(const char* name, int x) const{
  glUniform1i(glGetUniformLocation(program, name), x);
}

void Shader::useUniformMat4f(const char* name, const gml::mat4& matrix) const{
  glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, (float*)&matrix);
}

void Shader::bind() const{
  glUseProgram(program);
}

void Shader::unbind() const{
  glUseProgram(0);
}

Shader::~Shader(){
  glDeleteProgram(program);
}
