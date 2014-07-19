#version 430
 
in vec3 rotatedNormal;
in vec3 rotatedTangent;
in vec3 rotatedBitangent;
in vec3 modelToWorldPosition;
in vec4 ambientColor;
in vec4 objectColor;
in vec2 UV;

uniform vec3 lightPosition;
uniform float diffusionIntensity;
uniform vec4 specularColor;
uniform float specularExponent;
uniform vec3 eyePosition;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;
uniform sampler2D ambientOcclusionMap;

uniform int hasDiffuseMap;
uniform int hasNormalMap;
uniform int hasAmbientOcclusion;

uniform float burnThreshold;
uniform float octaveIndex;

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
		
		mat3 normalRotation = mat3(rotatedTangent,rotatedBitangent,rotatedNormal);
		normRotated = normalRotation*normalFromMap;
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

	vec4 finalAmbient = ambientColor;

	theFinalColor= (finalAmbient + vec4(brightness, brightness, brightness, 1))* objectColor + specularLighting;
	if(hasDiffuseMap>0)
	{
		vec4 texel = texture(diffuseMap, UV);
		theFinalColor= texel * theFinalColor;
		theFinalColor.a = texel.a;
	}
	
	if(hasAmbientOcclusion>0)
	{
		vec4 texel = texture(ambientOcclusionMap, UV);
		int index = int(octaveIndex);
		float noiseValue = texel[index];
		if(noiseValue>burnThreshold)
		{
			discard;
		}
		else if(noiseValue+0.02f>burnThreshold)
		{
			theFinalColor = vec4(0,0.4f,0.5f,0.5f);
		}
	}
}