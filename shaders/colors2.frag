#version 410 core

// in vec4 gl_FragCoord;
//
//      layout(origin_upper_left) in vec4 gl_FragCoord;
//      layout(origin_upper_left) in vec4 gl_FragCoord;
//
// in bool gl_FrontFacing;
// in vec2 gl_PointCoord;
//
//      in int gl_SampleID;
//      in vec2 gl_SamplePosition;
//      in int gl_SampleMaskIn[];
//
//      in float gl_ClipDistance[];
//      in int gl_PrimitiveID;
//
//      in int gl_Layer;
//      in int gl_ViewportIndex;
//
// out float gl_FragDepth;
//
// struct gl_DepthRangeParameters
// {
//     float near;
//     float far;
//     float diff;
// };
// uniform gl_DepthRangeParameters gl_DepthRange;
// uniform int gl_NumSamples; // GLSL 4.20

out vec4 col;
uniform vec2 iResolution;

void main() {
    // vec2 uv = (2.0 * gl_FragCoord.xy - iResolution.xy) / iResolution.y;
    // col = vec4(0.5, uv, 1.0);
    col = vec4(gl_FragCoord.x / iResolution.x, gl_FragCoord.y / iResolution.y, 0.5, 1.0);
}
