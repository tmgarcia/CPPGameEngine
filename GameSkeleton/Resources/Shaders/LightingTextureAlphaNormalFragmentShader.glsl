#version 430
 
in vec3 rotatedNormal; 
in vec3 modelToWorldPosition;
in vec4 ambientColor;
in vec4 objectColor;
in vec2 UV;

in mat4 rotationMat;

uniform vec3 lightPosition;
uniform float diffusionIntensity;
uniform vec4 specularColor;
uniform float specularExponent;
uniform vec3 eyePosition;

uniform sampler2D baseTexture;
uniform sampler2D alphaMap;
uniform sampler2D normalMap;

uniform int hasTexture;
uniform int hasAlphaMap;
uniform int hasNormalMap;

out vec4 theFinalColor; 
 
void main() 
{ 
	vec3 normRotated = rotatedNormal;
	if(hasNormalMap>0)
	{
		vec4 normTexel = texture(normalMap, UV);
		vec3 normalFromMap = vec3(0,0,0);
		normalFromMap.x = (normTexel.x*2)-1;
		normalFromMap.y = (normTexel.y*2)-1;
		normalFromMap.z = (normTexel.z*2)-1;
		//normRotated = mat3(rotationMat) * normalFromMap;
		normRotated = normalFromMap;
	}
	vec3 lightVector = normalize(lightPosition - modelToWorldPosition);
	float brightness = dot(lightVector, normRotated);
	brightness *= diffusionIntensity;

	vec3 specularLightVector = normalize(modelToWorldPosition - lightPosition);
	vec3 eyeVector = normalize(modelToWorldPosition - eyePosition);
	vec3 reflectedLight = reflect(specularLightVector, normRotated);
	float specularAngle = clamp(-dot(reflectedLight, eyeVector), 0, 1);

	specularAngle = pow(specularAngle, specularExponent);

	vec4 specularLighting = specularColor * specularAngle;

	theFinalColor= (ambientColor + vec4(brightness, brightness, brightness, 1))* objectColor + specularLighting;
	if(hasTexture>0)
	{
		vec4 texel = texture(baseTexture, UV);
		theFinalColor= texel * theFinalColor;
		theFinalColor.a = texel.a;
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