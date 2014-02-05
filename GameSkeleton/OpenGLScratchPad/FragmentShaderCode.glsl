#version 430
 
in vec3 theNormal; 
in vec3 thePosition;
in vec4 ambientColor;
in vec4 objectColor;

uniform vec3 lightPosition;
uniform float isLightBulb;
uniform float diffusionIntensity;
uniform vec4 specularColor;
uniform float specularExponent;
uniform vec3 eyePosition;


out vec4 theFinalColor; 
 
void main() 
{ 
	vec3 lightVector = normalize(lightPosition - thePosition);
	float brightness = dot(lightVector, theNormal);
	brightness *= diffusionIntensity;

	vec3 specularLightVector = normalize(thePosition - lightPosition);
	vec3 eyeVector = normalize(thePosition - eyePosition);
	vec3 reflectedLight = reflect(specularLightVector, theNormal);
	float specularAngle = clamp(-dot(reflectedLight, eyeVector), 0, 1);

	specularAngle = pow(specularAngle, specularExponent);

	vec4 specular = specularColor * specularAngle;

	if(isLightBulb==1.0f)
	{
		theFinalColor = vec4(1.0, 1.0f, 1.0f, 1.0f);
	}
	else
	{
		theFinalColor= (ambientColor + vec4(brightness, brightness, brightness, 1))* objectColor + specular;
	}
}