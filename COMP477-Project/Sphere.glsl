////////////////////////////////////////
// Model.glsl
////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

#ifdef VERTEX_SHADER

layout(location=0) in vec3 Position;
layout(location=1) in vec3 Normal;
layout(location=2) in mat4 ModelMtx;

out vec3 fragPosition;
out vec3 fragNormal;

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

uniform vec3 LightDirection=normalize(vec3(-1,0,0));
uniform vec3 LightColor=vec3(0.7, 0.7, 0.7);
uniform vec3 DiffuseColor=vec3(0.70,0.75,0.79);

out vec3 finalColor;

////////////////////////////////////////
// Fragment shader
////////////////////////////////////////

void main() {
	// Compute irradiance (sum of ambient & direct lighting)
	vec3 irradiance= vec3(0.7,0.7,0.7) * DiffuseColor + DiffuseColor * LightColor * max(0,dot(LightDirection,normalize(fragNormal)));
	
	// Gamma correction
	gl_FragColor=vec4(irradiance,1);
}

#endif

////////////////////////////////////////////////////////////////////////////////
