#version 430 
 
in layout(location=0) vec3 passedInPosition;

uniform mat4 fullTransformMatrix;
uniform float isCrossHair;
uniform mat4 rotation;
uniform vec4 passedColor;

out vec4 color;

void main()
{
	gl_Position = fullTransformMatrix * vec4(passedInPosition, 1.0f);
	if(isCrossHair == 1.0f)
	{
		vec4 rotatedPosition = rotation * vec4(passedInPosition, 1.0f);
		color = vec4(0+rotatedPosition.x, 0+rotatedPosition.y, 0+rotatedPosition.z, 1.0f);
	}
	else if(isCrossHair == 2.0f)
	{
		color = passedColor;
		color.x += passedInPosition.x *0.5f;
		color.y += passedInPosition.y *0.5f;
		color.z += passedInPosition.z *0.5f;
	}
	else
	{
		color = passedColor;
	}
}