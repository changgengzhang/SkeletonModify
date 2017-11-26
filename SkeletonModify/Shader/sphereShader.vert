#version 330 core
// in
layout (location=0) in vec3 position;
layout (location=1) in vec3 normal;
// uniform values
uniform mat4 modelMat;
uniform mat4 vpMat;

out VSOUT
{
	vec3 normal;
	vec3 worldPos;
}vsOut;

out vec3 tmp;

void main()
{
	gl_Position = vpMat * modelMat * vec4(position, 1.0f);
	vsOut.normal = mat3(transpose(inverse(modelMat))) * normal;
	//vsOut.normal = position;
	vsOut.worldPos = vec3(modelMat * vec4(position, 1.0f));
}