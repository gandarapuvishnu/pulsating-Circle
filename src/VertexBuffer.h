#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(const float* data, unsigned int size, unsigned int draw_type);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};
