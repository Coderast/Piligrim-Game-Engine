#include "vertexarray.h"



VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &id_));
	buffer_ = nullptr;
}



void VertexArray::setBuffer(Buffer* buffer)
{
	buffer_ = buffer;
}



void VertexArray::addBufferAttributes(GLuint index, GLuint elementCount, GLsizei stride, GLuint leftPaddingInBytes)
{
	GLCall(glBindVertexArray(id_));

	buffer_->bind();

	GLCall(glEnableVertexAttribArray(index));
	GLCall(glVertexAttribPointer(index, elementCount, GL_FLOAT, GL_FALSE, stride, (GLvoid*)leftPaddingInBytes));

	GLCall(glBindVertexArray(0));
}



void VertexArray::bind() const
{
	GLCall(glBindVertexArray(id_));
}



void VertexArray::unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::deleteBuffer() const
{
	if (buffer_ != nullptr)
		delete buffer_;
}