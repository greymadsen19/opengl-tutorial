#include "loadshaders.h"

#include <math.h>

static GLuint vao;
static GLuint vbo;

void init(void) {
	const GLfloat vertices[3][2] = {
		{ -0.5f, -0.1f},
		{ 0.1f, 0.5f },
		{ 0.1f, -0.1f }
	};

	shaderinfo shaders[3] = {
		{ GL_VERTEX_SHADER, "triangle.vs" },
		{ GL_FRAGMENT_SHADER, "triangle.fs" },
		{ GL_NONE, NULL }
	};

	GLuint program = loadshaders(shaders);
	glUseProgram(program);

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

void render(double currentTime) {
	GLfloat color[4] = { 0.0f, (float)cos(currentTime) * 0.5f + 0.5f, (float)sin(currentTime) * 0.5f + 0.5f, 1.0f };

	glClearBufferfv(GL_COLOR, 0, color);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}