#version 120

varying vec2 texCoordVarying;

// this is the default vertex shader:

void main()
{
    texCoordVarying = gl_MultiTexCoord0.xy;
    gl_Position = ftransform();
}