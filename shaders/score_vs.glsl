#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 pTexturePosition;

out vec2 texturePosition;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

void main(){
  gl_Position = projectionMatrix * modelMatrix * position;
  texturePosition = pTexturePosition;
}
