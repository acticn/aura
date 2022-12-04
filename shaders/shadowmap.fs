#version 330 core

in vec3 fragPos;

out vec4 FragColor;

uniform vec3 viewPos;

void main() {
	
	float value = length(fragPos-viewPos);
	value = (gl_FragCoord.z+1)/2;
	FragColor = vec4(value,value,value,1.0);
}