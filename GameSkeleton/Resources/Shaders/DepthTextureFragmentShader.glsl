#version 430

in vec2 UV;

uniform sampler2D diffuseMap;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec4 texel = texture(diffuseMap, UV);
	theFinalColor= texel * vec4(1,1,1,1);
	theFinalColor.x = pow(theFinalColor.x,50);
	theFinalColor.y = pow(theFinalColor.y,50);
	theFinalColor.z = pow(theFinalColor.z,50);
	theFinalColor.a = 1;
}