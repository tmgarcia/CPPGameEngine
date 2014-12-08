#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInTangent; 
in layout(location=2) vec3 passedInNormal;
in layout(location=3) vec2 passedInUV;

uniform mat4 fullTransformMatrix;
 
out vec2 UV;

void main() 
{ 
	vec4 v = vec4(passedInPosition,1.0f); 
	gl_Position = fullTransformMatrix * v;

	UV = passedInUV;
} 