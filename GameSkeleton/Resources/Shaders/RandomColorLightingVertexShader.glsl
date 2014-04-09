#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInColor; 
in layout(location=2) vec3 passedInNormal;

uniform mat4 fullTransformMatrix;
uniform vec3 ambientLight;
uniform mat4 rotationMatrix;
uniform mat4 modelToWorldMatrix;
 
out vec3 rotatedNormal;
out vec3 modelToWorldPosition;
out vec4 ambientColor;

void main() 
{ 
	vec4 v = vec4(passedInPosition,1.0f); 
	gl_Position = fullTransformMatrix * v;
	modelToWorldPosition = vec3(modelToWorldMatrix * v);
	rotatedNormal = mat3(rotationMatrix) * passedInNormal;
	ambientColor = vec4(ambientLight, 1.0f);
} 