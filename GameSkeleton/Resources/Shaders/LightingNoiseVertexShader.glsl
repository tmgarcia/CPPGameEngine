#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInTangent; 
in layout(location=2) vec3 passedInNormal;
in layout(location=3) vec2 passedInUV;

uniform mat4 fullTransformMatrix;
uniform vec3 overridingObjectColor;
uniform vec3 ambientLight;
uniform mat4 rotationMatrix;
uniform mat4 modelToWorldMatrix;
 
out vec3 rotatedNormal;
out vec3 rotatedTangent;
out vec3 rotatedBitangent;
out vec3 modelToWorldPosition;
out vec4 ambientColor;
out vec4 objectColor;
out vec2 UV;


void main() 
{ 
	vec4 v = vec4(passedInPosition,1.0f); 
	gl_Position = fullTransformMatrix * v;
	modelToWorldPosition = vec3(modelToWorldMatrix * v);
	
	float handedness = passedInTangent.w;
	rotatedNormal = mat3(rotationMatrix) * passedInNormal;
	rotatedTangent = mat3(rotationMatrix) * vec3(passedInTangent);
	vec3 bitangent = handedness*(cross(passedInNormal,vec3(passedInTangent)));
	rotatedBitangent = mat3(rotationMatrix) * bitangent;
	
	ambientColor = vec4(ambientLight, 1.0f);
	objectColor = vec4(overridingObjectColor, 1.0f);
	UV = passedInUV;
} 