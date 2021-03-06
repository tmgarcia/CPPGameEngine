#version 430

in vec2 UV;

uniform sampler2D diffuseMap;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec4 texel = texture(diffuseMap, UV);
	theFinalColor= texel * vec4(1,1,1,1);
	theFinalColor.a = 1;
}