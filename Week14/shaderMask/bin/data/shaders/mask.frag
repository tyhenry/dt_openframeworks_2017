#version 120

uniform sampler2D tex0;
uniform sampler2D imgMask;

varying vec2 texCoordVarying;

// note: in shaders, color values range (0.0 - 1.0) not (0-255)
// so we can easily add, subtract and multiply colors

void main()
{
	// get rgba color from base texture
    vec4 color 		= texture2D(tex0, texCoordVarying);

    // use red channel of img mask for new alpha
    float mask 	= texture2D(imgMask, texCoordVarying).r;

    color.a -= mask;	// apply the mask

    gl_FragColor = color;
}