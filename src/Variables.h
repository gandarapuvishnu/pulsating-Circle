#pragma once

#include <math.h>

#define PI 3.14

float angle(float x)
{
    return { float(x * PI / 180.0f) };
}

//Pulsating Circle
float radius = 0.5f;

float positions[360 * 2 + 2]{};
unsigned int indices[360 * 3]{};

void assign()
{

    for (int i = 0; i < (360 * 2 + 2); i++)
    {
        if (i < 2)
            positions[i] = 0.0f;
        else if (i & 1)
            positions[i] = radius * cosf(angle(i - 2));
        else
            positions[i] = radius * sinf(angle(i - 2));
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
}
