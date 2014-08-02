#version 430

in vec3 reflectionDirection;

uniform samplerCube cubeMap;
uniform float reflectionFactor;
uniform vec3 overridingObjectColor;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec4 texel = texture(cubeMap, reflectionDirection);
	theFinalColor= mix(vec4(overridingObjectColor,1),texel,reflectionFactor);
	theFinalColor.a = 1;
}