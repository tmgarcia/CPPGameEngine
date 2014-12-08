#version 430

in vec2 UV;

uniform sampler2D diffuseMap;
uniform sampler2D alphaMap;

uniform int hasDiffuseMap;
uniform int hasAlphaMap;

out vec4 theFinalColor; 
 
void main() 
{ 
	theFinalColor = vec4(0,0,0,1);
	if(hasDiffuseMap>0)
	{
		vec4 textureTexel = texture(diffuseMap, UV);
		theFinalColor = textureTexel;
	}
	if(hasAlphaMap>0)
	{
		vec4 alphaTexel = texture(alphaMap, UV);
		if(alphaTexel.r > 0.5 )
		{
			discard;
		}
	}
}