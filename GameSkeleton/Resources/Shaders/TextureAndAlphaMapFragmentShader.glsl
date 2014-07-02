#version 430

in vec4 color;
in vec2 UV;

uniform sampler2D baseTexture;
uniform sampler2D alphaMap;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec4 alphaTexel = texture(alphaMap, UV);
	vec4 textureTexel = texture(baseTexture, UV);
	theFinalColor = color;
	theFinalColor = textureTexel;
	if(alphaTexel.r > 0.5 )
		discard;
}