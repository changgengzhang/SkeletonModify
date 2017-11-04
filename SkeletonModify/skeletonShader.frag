#version 330 core

in VSOUT
{
	vec3 color;
}fsIn;

out vec4 fragColor;

void main()
{
	fragColor = vec4(fsIn.color, 1.0f);	
} 