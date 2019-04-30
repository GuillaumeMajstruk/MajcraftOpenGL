#version 330 core

out vec4 color;
in vec2 texCoord;

uniform sampler2D theTexture;

void main()
{
    color = texture(theTexture, texCoord);
}
