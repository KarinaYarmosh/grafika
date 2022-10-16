//
// Created by DAN on 02.10.2022.
//

#include <GLFW/glfw3.h>
#include "FpsLimiter.h"
static double limitFPS = 1.0 / 60.0;

    double lastTime = glfwGetTime(), timer = lastTime;
    double deltaTime = 0, nowTime = 0;
    int frames = 0 , updates = 0;

    // - While window is alive
    while(!window.closed()) {

        // - Measure time
        nowTime = glfwGetTime();
        deltaTime += (nowTime - lastTime) / limitFPS;
        lastTime = nowTime;

        // - Only update at 60 frames / s
        while (deltaTime >= 1.0){
            update();   // - Update function
            updates++;
            deltaTime--;
        }
        // - Render at maximum possible frames
        render(); // - Render function
        frames++;

        // - Reset after one second
        if (glfwGetTime() - timer > 1.0) {
            timer ++;
            std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
            updates = 0, frames = 0;
        }

    }
