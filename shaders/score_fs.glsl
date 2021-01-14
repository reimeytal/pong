#version 330 core
layout(location = 0) out vec4 color;

in vec2 texturePosition;
uniform sampler2D scoreTexture;

void main(){
  color = texture(scoreTexture, texturePosition);
}
