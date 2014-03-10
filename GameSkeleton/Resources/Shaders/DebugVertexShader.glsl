#version 430 
 
in layout(location=0) vec3 passedInPosition; 
in layout(location=1) vec4 passedInColor;

uniform mat4 fullTransformMatrix;
uniform float isCrossHair;
uniform mat4 rotation;

out vec4 color;

void main()
{
	gl_Position = fullTransformMatrix * vec4(passedInPosition, 1.0f);
	if(isCrossHair == 1.0f)
	{
		vec4 rotatedPosition = rotation * vec4(passedInPosition, 1.0f);
		color = vec4(0+rotatedPosition.x, 0+rotatedPosition.y, 0+rotatedPosition.z, 1.0f);
	}
	else
	{
		color = passedInColor;
	}
}