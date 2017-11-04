#version 330 core

in VSOUT
{
	vec2 uv;
}fsIn;

out vec4 fragColor;

uniform sampler2D backdrop;

void main()
{
	fragColor = texture(backdrop, fsIn.uv);	
} 