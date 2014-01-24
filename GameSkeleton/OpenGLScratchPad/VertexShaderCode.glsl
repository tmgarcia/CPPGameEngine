#version 400 
 
in layout(location=0) vec3 position; 
in layout(location=1) vec4 color; 
 
uniform mat4 fullTransformMatrix;

out vec4 deColor; 
 
void main() 
{ 
	vec4 v = vec4(position,1.0f); 
	gl_Position = fullTransformMatrix * v;
	deColor = color; 
} 