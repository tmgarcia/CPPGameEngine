#version 430

in vec4 color;
in vec2 UV;

uniform sampler2D tex;

out vec4 theFinalColor; 
 
void main() 
{ 
	theFinalColor= color;
	theFinalColor= texture(tex, UV);
}