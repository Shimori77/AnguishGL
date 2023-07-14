#version 460 core

in vec3 vVertColor;
in vec2 frag_vTextureUV;

out vec4 FragColor;

layout (binding = 0) uniform sampler2D diffuseTextureSampler;

uniform float iTime;

vec3 palette(float t) {
    vec3 a = vec3(0.5, 0.5, 0.5);
    vec3 b = vec3(0.5, 0.5, 0.5);
    vec3 c = vec3(1.0, 1.0, 1.0);
    vec3 d = vec3(0.236, 0.416, 0.557);

    return a + b * cos(6.28318 * (c * t + d));
}

void main(void) {
    vec2 res = vec2(1366, 768);
    vec2 uv = (gl_FragCoord.xy * 2.0 - res) / res.y;
    vec2 uv0 = uv;

    vec3 finalColor = vec3(0.0);

    for (float i = 0.0; i < 4.0; i++) {
        uv = fract(uv * 1.5) - 0.5;

        float d = length(uv) * exp(-length(uv0));
        vec3 color = palette(length(uv0) + i * 0.4 + iTime * 0.4);

        d = sin(d * 8.0 + iTime) / 8.0;
        d = abs(d);
        d = pow(0.01 / d, 2.0);

        finalColor += color * d;
    }

    FragColor = vec4(finalColor, 1.0);
}