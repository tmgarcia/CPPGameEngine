#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInColor;

uniform mat4 fullTransformMatrix;


out vec4 color;

void main()
{
	gl_Position = fullTransformMatrix * vec4(passedInPosition, 1.0f);
	color = passedInColor;
}