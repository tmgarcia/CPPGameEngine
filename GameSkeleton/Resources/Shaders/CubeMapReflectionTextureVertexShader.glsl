#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInTangent; 
in layout(location=2) vec3 passedInNormal;
in layout(location=3) vec2 passedInUV;

uniform mat4 fullTransformMatrix;
uniform mat4 modelToWorldMatrix;
uniform mat4 rotationMatrix;
uniform vec3 eyePosition;
 
out vec3 reflectionDirection;

void main() 
{ 
	vec4 v = vec4(passedInPosition,1.0f);
	vec3 modelToWorldPosition = vec3(modelToWorldMatrix * v);
	vec3 rotatedNormal = mat3(rotationMatrix) * passedInNormal;
	vec3 positionToEye = normalize(modelToWorldPosition - eyePosition);
	reflectionDirection = reflect(-positionToEye, rotatedNormal);
	
	gl_Position = fullTransformMatrix * v;
} 
