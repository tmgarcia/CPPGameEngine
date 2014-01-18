#version 400 
 
in layout(location=0) vec4 position; 
in layout(location=1) vec4 color; 
 
uniform mat3 currentTransform; 
uniform vec3 dominatingColor; 
uniform float zAdjustment; 
 
out vec4 deColor; 
 
void main() 
{ 
	gl_Position = position; 
	gl_Position = gl_Position*mat4(currentTransform); 
	gl_Position.z = gl_Position.z + zAdjustment; 
	deColor = color; 
	deColor.z = dominatingColor.z; 
} 