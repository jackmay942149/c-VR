#version 330 core
out vec4 FragColor;
in vec4 gl_FragCoord;

void main() {
    FragColor = vec4(1 - pow(gl_FragCoord.z, 4), 0.0f, 0.0f, 1.0f);
} 
