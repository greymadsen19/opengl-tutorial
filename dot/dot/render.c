#include "loadshaders.h"

#include <stddef.h>
#include <math.h>

GLuint vao;
GLuint vbo;

void init(void) {
	GLfloat dot[] = { -0.5f, 0.5f };

	shaderinfo shaders[3] = {
		{ GL_VERTEX_SHADER, "dot.vs" },
		{ GL_FRAGMENT_SHADER, "dot.fs" },
		{ GL_NONE, NULL }
	};

	GLuint program = loadshaders(shaders);
	glUseProgram(program);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dot), dot, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

void render(void) {
	static const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glClearBufferfv(GL_COLOR, 0, color);

	glPointSize(50.0f);
	glDrawArrays(GL_POINTS, 0, 1);
}