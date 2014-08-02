#version 430

in vec3 reflectionDirection;

uniform samplerCube cubeMap;

out vec4 theFinalColor; 

void main() 
{ 
	vec4 texel = texture(cubeMap, reflectionDirection);
	theFinalColor= texel;
	theFinalColor.a = 1;
}