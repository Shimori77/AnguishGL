#version 460 core

layout (location = 0) in vec2 vPos;
layout (location = 1) in vec2 vTextureUV;

out vec3 vVertColor;
out vec2 frag_vTextureUV;

uniform mat4 mvp;

void main(void) {
    vec4 position = mvp * vec4(vPos, 0.0, 1.0);

    gl_Position = position;

    vVertColor = vec3(normalize(vPos.x) + 0.5, normalize(vPos.y) + 0.5, 1.0);

    frag_vTextureUV = vTextureUV;
}