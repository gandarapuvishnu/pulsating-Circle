#pragma once

#include <gl/glew.h>

//debugbreak() is a MSVC debugger break point
#define ASSERT(x) if(!(x))__debugbreak();

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__,__LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& vb, const IndexBuffer& ib, const Shader& shader, const bool wireframeMode) const;
};