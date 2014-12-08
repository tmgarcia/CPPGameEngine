#version 430

in vec2 UV;

uniform sampler2D diffuseMap;
uniform sampler2D alphaMap;

uniform int hasDiffuseMap;
uniform int hasAlphaMap;
uniform int offsetDiffuse;
uniform int offsetAlpha;
uniform vec2 UVOffset;

out vec4 theFinalColor; 
 
void main() 
{
	theFinalColor = vec4(0,0,0,1);
	if(hasDiffuseMap>0)
	{
		vec2 diffuseUV = UV;
		if(offsetDiffuse>0)
		{
			diffuseUV += UVOffset;
		}
		vec4 textureTexel = texture(diffuseMap, diffuseUV);
		theFinalColor = textureTexel;
		
		
	}
	if(hasAlphaMap>0)
	{
		vec2 alphaUV = UV;
		if(offsetAlpha>0)
		{
			alphaUV += UVOffset;
		}
		vec4 alphaTexel = texture(alphaMap, alphaUV);
		if(alphaTexel.r > 0.7 )
		{
			discard;
		}
		else
		{
			theFinalColor.a = (1-alphaTexel.r);
		}
	}
}