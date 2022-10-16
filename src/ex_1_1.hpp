#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <chrono>

#include "Shader_Loader.h"
#include "Render_Utils.h"


double GetTime()
{
    using Duration = std::chrono::duration<double>;
    return std::chrono::duration_cast<Duration>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

const double frame_delay = 1.0 / 60.0; // 60 FPS


float * randomRGBA() {
    auto * colors = new float [3];
    colors[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    colors[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    colors[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return colors;
}

// funkcja renderujaca scene    
void renderScene(GLFWwindow* window)
{
    // ZADANIE: Przesledz kod i komentarze
    // ZADANIE: Zmien kolor tla sceny, przyjmujac zmiennoprzecinkowy standard RGBA
    float *color = randomRGBA();
    std::cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<std::endl;
    glClearColor(color[0], color[1], color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Powinno byc wywolane po kazdej klatce
    glfwSwapBuffers(window);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void init(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void shutdown(GLFWwindow* window)
{
}

//obsluga wejscia
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// funkcja jest glowna petla
void renderLoop(GLFWwindow* window, const float TARGET_FPS) {

    double lasttime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        lasttime += 1.0/TARGET_FPS;
        processInput(window);

        renderScene(window);
        glfwPollEvents();
        while (glfwGetTime() < lasttime + 1.0/TARGET_FPS) {
                std::cout<<"lol";
        }

    }
}
