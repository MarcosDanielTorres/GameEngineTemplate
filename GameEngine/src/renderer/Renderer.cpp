#include "Renderer.h"
#include<iostream>
void Renderer::prepare() {
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(RawModel model, int attributeNumber, int attributeNumber2) {
	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(attributeNumber);
	glEnableVertexAttribArray(attributeNumber2);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(attributeNumber);
	glDisableVertexAttribArray(attributeNumber2);
	glBindVertexArray(0);
}

