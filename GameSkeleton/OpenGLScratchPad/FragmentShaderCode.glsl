#version 430
 
in vec3 theNormal; 
in vec3 thePosition;
in vec4 ambientColor;
in vec4 objectColor;

uniform vec3 lightPosition;
uniform float isLightBulb;
uniform float diffusionIntensity;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec3 lightVector = normalize(lightPosition - thePosition);
	float brightness = dot(lightVector, theNormal);
	if(isLightBulb==1.0f)
	{
		theFinalColor = vec4(1.0, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		theFinalColor= objectColor*(ambientColor + (brightness*diffusionIntensity));
	}
}