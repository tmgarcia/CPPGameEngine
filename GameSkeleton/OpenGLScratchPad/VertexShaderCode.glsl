#version 400 
 
in layout(location=0) vec3 position; 
in layout(location=1) vec4 color; 
 
uniform mat4 fullTransformMatrix;
uniform vec3 newColor;

out vec4 deColor; 
 
void main() 
{ 
	vec4 v = vec4(position,1.0f); 
	gl_Position = fullTransformMatrix * v;
	deColor = color;
	deColor.x += newColor.x; 
	deColor.y += newColor.y; 
	deColor.z += newColor.z; 
} 