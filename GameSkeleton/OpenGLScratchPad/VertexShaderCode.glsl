#version 430 
 
in layout(location=0) vec3 position; 
in layout(location=1) vec4 color; 
in layout(location=2) vec3 normal;
in layout(location=3) vec2 vertexUV;

uniform mat4 fullTransformMatrix;
uniform vec3 newColor;
uniform vec3 ambientLight;
uniform mat4 rotationMatrix;
uniform mat4 modelToWorldMatrix;
 
out vec3 theNormal;
out vec3 thePosition;
out vec4 ambientColor;
out vec4 objectColor;
out vec2 UV;

void main() 
{ 
	vec4 v = vec4(position,1.0f); 
	gl_Position = fullTransformMatrix * v;
	thePosition = vec3(modelToWorldMatrix * v);
	theNormal = mat3(rotationMatrix) * normal;
	ambientColor = vec4(ambientLight, 1.0f);
	objectColor = vec4(newColor, 1.0f);
	UV = vertexUV;
} 