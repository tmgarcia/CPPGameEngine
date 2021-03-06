#version 430
 
in vec3 rotatedNormal; 
in vec3 modelToWorldPosition;
in vec4 ambientColor;
in vec4 objectColor;
in vec2 UV;

uniform vec3 lightPosition;
uniform float diffusionIntensity;
uniform vec4 specularColor;
uniform float specularExponent;
uniform vec3 eyePosition;
uniform sampler2D tex;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec3 lightVector = normalize(lightPosition - modelToWorldPosition);
	float brightness = dot(lightVector, rotatedNormal);
	brightness *= diffusionIntensity;

	vec3 specularLightVector = normalize(modelToWorldPosition - lightPosition);
	vec3 eyeVector = normalize(modelToWorldPosition - eyePosition);
	vec3 reflectedLight = reflect(specularLightVector, rotatedNormal);
	float specularAngle = clamp(-dot(reflectedLight, eyeVector), 0, 1);

	specularAngle = pow(specularAngle, specularExponent);

	vec4 specularLighting = specularColor * specularAngle;

	theFinalColor= (ambientColor + vec4(brightness, brightness, brightness, 1))* objectColor + specularLighting;
	vec4 texel = texture(tex, UV);
	theFinalColor= texel * theFinalColor;
	theFinalColor.a = texel.a;
}