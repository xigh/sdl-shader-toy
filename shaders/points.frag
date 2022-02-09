#version 410 core

// Constants from CPU
uniform vec2 iResolution;
uniform vec2 iMouse;
uniform float iTime;

// World dimension
vec2 uv;

// Background color
float r = 0.0;
float g = 0.0;
float b = 0.4;
float a = 1.0;

// Zoom
float zoom = 0.03;

// Final color
out vec4 fragColor;

// Draw a point
float point(vec2 position)
{
    vec2 ms = (2.0 * position - iResolution.xy) / iResolution.y;
    ms.y = -ms.y; // y is inverted
    return max(0.1, smoothstep(1.0, 0.9, length(uv - ms) / zoom));
}

// Draw the mouse cursor
float cursor()
{
    return point(iMouse);
}

void main()
{
    uv = (2.0 * gl_FragCoord.xy - iResolution.xy) / iResolution.y;

    r += cursor();
    g += point(vec2(400, 400));
    b += point(vec2(40, 400));

    fragColor = vec4(max(vec3(r, g, b), 0.1), a);
}
