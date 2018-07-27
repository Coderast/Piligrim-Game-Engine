#version 330 core

layout (location = 0) in vec3 position;
/*layout (location = 1) in vec4 in_color;*/

uniform mat4 u_pr_matrix;
uniform mat4 u_vw_matrix = mat4(1.0);
uniform mat4 u_ml_matrix = mat4(1.0);

void main()
{
	gl_Position = u_pr_matrix * u_vw_matrix * u_ml_matrix * vec4(position, 1.0);
}
