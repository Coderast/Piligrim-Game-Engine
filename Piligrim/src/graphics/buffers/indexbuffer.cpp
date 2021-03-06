#include "indexbuffer.h"



IndexBuffer::IndexBuffer(GLuint *data, GLuint count, GLenum drawMode)
{
	set(data, count, drawMode);
}



void IndexBuffer::set(GLuint * data, GLuint count, GLenum  drawMode)
{
	count_ = count;
	GLCall(glGenBuffers(1, &id_));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, drawMode));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}



void IndexBuffer::bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_));
}



void IndexBuffer::unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

