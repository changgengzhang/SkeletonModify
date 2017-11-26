#version 330 core

out vec4 fragColor;

in VSOUT
{
	vec3 normal;
	vec3 worldPos;
}fsIn;

in vec3 tmp;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	float ambientWeight = 0.1;
	float specularWeight = 0.5;
	vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

	vec3 ambient = ambientWeight * lightColor;

	vec3 lightDire = normalize(lightPos - fsIn.worldPos);
	vec3 normal = normalize(fsIn.normal);
	float diff = max(dot(lightDire, normal), 0.0f);
	vec3 diffuse = diff * lightColor;

	// specular  Blinn-Phong
	vec3 viewDire = normalize(viewPos - fsIn.worldPos);
	vec3 halfwayDire = normalize(lightDire + viewDire);
	float spec = pow(max(dot(viewDire, halfwayDire), 0.0f), 32.0f);
	vec3 specular = spec * specularWeight * lightColor;

	vec3 total = ambient + diffuse + specular;

	fragColor = vec4(vec3(1.0, 1.0f, 1.0f) * total, 1.0f);

} 