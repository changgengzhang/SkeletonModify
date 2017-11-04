#version 330 core
// in
layout (location=0) in vec3 position;
layout (location=1) in vec2 uv;

// uniform values
uniform mat4 mvpMat;

// out
out VSOUT
{
	vec2 uv;
}vsOut;


void main()
{
	gl_Position = mvpMat * vec4(position, 1.0f);
	vsOut.uv = uv;
}