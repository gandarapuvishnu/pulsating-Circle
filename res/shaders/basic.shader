#shader vertex
#version 330 core
layout(location = 0) in vec4 position;

uniform vec4 u_Color;
out vec4 vertexColor;

void main()
{
   gl_Position = vec4(position.x, position.y, position.z, 1.0f);

   vertexColor = u_Color;
};

#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec4 vertexColor;

void main()
{
   color = vertexColor;
};