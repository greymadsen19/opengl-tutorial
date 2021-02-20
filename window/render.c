#include "render.h"

void render(void) {
	static const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glClearBufferfv(GL_COLOR, 0, color);
}