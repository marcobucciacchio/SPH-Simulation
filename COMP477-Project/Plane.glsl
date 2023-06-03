//Plane.glsl

#ifdef VERTEX_SHADER

layout(location=0) in vec3 Position;
layout(location=1) in vec3 Normal;

out vec3 fragPosition;
out vec3 fragNormal;
out vec4 gl_FragColor;


uniform mat4 ModelMtx=mat4(1);
uniform mat4 viewProjMtx=mat4(1);

////////////////////////////////////////
// Vertex shader
////////////////////////////////////////

void main() {
	gl_Position=viewProjMtx * ModelMtx * vec4(Position,1);

	fragPosition=vec3(ModelMtx * vec4(Position,1));
	fragNormal=vec3(ModelMtx * vec4(Normal,0));
}

#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef FRAGMENT_SHADER

in vec3 fragPosition;
in vec3 fragNormal;

////////////////////////////////////////
// Fragment shader
////////////////////////////////////////

void main() {
	gl_FragColor=vec4(0.094, 0.165, 0.6, 1.0f);
}	

#endif

////////////////////////////////////////////////////////////////////////////////
