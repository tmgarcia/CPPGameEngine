#version 400 
 
in layout(location=0) vec3 position; 
in layout(location=1) vec4 color; 
 
uniform mat4 currentTransform; 
uniform mat4 currentProjection;
 
out vec4 deColor; 
 
void main() 
{ 
	vec4 v = vec4(position,1.0f); 
	vec4 newPosition = currentTransform * v; 
	vec4 projectedPosition = currentProjection * newPosition;
	gl_Position = projectedPosition;
	deColor = color; 
} 