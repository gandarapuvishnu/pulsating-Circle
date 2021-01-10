
#include "Setup.h"

#include <iostream>

#include <math.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

#define PI 3.14

float angle(float x)
{
    return {float(x * PI / 180.0f)};
}

int main(void)
{   
    GLFWwindow* window = setup(800, 600);
    if(window)
    {   
        //Pulsating Circle
        float positions[360*2 + 2]{};
        unsigned int indices[360*3]{};

        for (int i = 0; i < (360 * 2 + 2); i++)
        {
            if (i < 2)
                positions[i] = 0.0f;
            else if (i & 1)
                positions[i] = cosf(angle(i - 2));
            else
                positions[i] = sinf(angle(i - 2));
        }

        for (unsigned int j = 0; j < (360 * 3); j++)
        {
            if (j < 3)
                indices[j] = j;
            else if (j % 3 == 0)
                indices[j] = 0;
            else if (j % 3 == 1)
                indices[j] = indices[j - 2];
            else if (j % 3 == 2)
                indices[j] = indices[j - 1] + 1;
        }

        VertexArray va;
        VertexBuffer vb(positions, sizeof(positions));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, sizeof(indices)/sizeof(unsigned int));

        Shader shader("res/shaders/basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        va.Unbind();
        shader.Unbind();
        vb.UnBind();
        ib.UnBind();

        float r = 0.0f;
        float increment = 0.05f;

        Renderer renderer;

        bool GL_WIREFRAME_MODE = false;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.Clear();

            //Weirdo here
            shader.Bind();
            shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

            renderer.Draw(va, ib, shader, GL_WIREFRAME_MODE);

            if (r > 1.0f)
                increment = -0.05f;
            else if (r < 0.0f)
                increment = 0.05f;

            r += increment;

            /* Swap front and back buffers */
            GLCall(glfwSwapBuffers(window));

            /* Poll for and process events */
            GLCall(glfwPollEvents());
        }
    }

    glfwTerminate();

    std::cin.get();
}