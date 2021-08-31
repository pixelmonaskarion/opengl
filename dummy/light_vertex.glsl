#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec4 Color;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 inColor;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    inColor = Color;
} 