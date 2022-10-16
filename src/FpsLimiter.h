//
// Created by DAN on 02.10.2022.
//

#ifndef UNTITLED2_FPSLIMITER_H
#define UNTITLED2_FPSLIMITER_H
#include <>

class FpsLimiter {
public:
    FpsLimiter();

    // Initializes the FPS limiter. For now, this is
    // analogous to setMaxFPS
    void Init(float maxFPS);

    // Sets the desired max FPS
    void SetMaxFPS(float maxFPS);

    void Begin();

    // end() will return the current FPS as a float
    float End();

    float deltaTime = 0.0f;
private:
    // Calculates the current FPS
    void CalculateFPS();

    // Variables
    float m_fps;
    float m_maxFPS;
    float m_frameTime;
    unsigned int m_startTicks;
    float lastDeltaTime = 0.0f;
    float nowDeltaTime = 0.0f;

};
FpsLimiter::FpsLimiter() {
}
void FpsLimiter::Init(float maxFPS) {
    SetMaxFPS(maxFPS);
}

void FpsLimiter::SetMaxFPS(float maxFPS) {
    m_maxFPS = maxFPS;
}

void FpsLimiter::Begin() {
    m_startTicks = SDL_GetTicks();
}

float FpsLimiter::End() {
    CalculateFPS();
    float nowDeltaTime = SDL_GetTicks();
    float frameTicks = (float)(SDL_GetTicks() - m_startTicks);
    //Limit the FPS to the max FPS
    if (1000.0f / m_maxFPS > frameTicks) {
        SDL_Delay((Uint32)(1000.0f / m_maxFPS - frameTicks));
    }
    if (nowDeltaTime > lastDeltaTime)
    {

        deltaTime = (nowDeltaTime - lastDeltaTime);
        lastDeltaTime = nowDeltaTime;
    }
    return m_fps;
}

void FpsLimiter::CalculateFPS() {
    //The number of frames to average
    static const int NUM_SAMPLES = 10;
    //Stores all the frametimes for each frame that we will average
    static float frameTimes[NUM_SAMPLES];
    //The current frame we are on
    static int currentFrame = 0;
    //the ticks of the previous frame
    static Uint32 prevTicks = SDL_GetTicks();

    //Ticks for the current frame
    Uint32 currentTicks = SDL_GetTicks();

    //Calculate the number of ticks (ms) for this frame
    m_frameTime = (float)(currentTicks - prevTicks);
    frameTimes[currentFrame % NUM_SAMPLES] = m_frameTime;

    //current ticks is now previous ticks
    prevTicks = currentTicks;

    //The number of frames to average
    int count;

    currentFrame++;
    if (currentFrame < NUM_SAMPLES) {
        count = currentFrame;
    } else {
        count = NUM_SAMPLES;
    }

    //Average all the frame times
    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++) {
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= count;

    //Calculate FPS
    if (frameTimeAverage > 0) {
        m_fps = 1000.0f / frameTimeAverage;
    } else {
        m_fps = 60.0f;
    }
}


#endif //UNTITLED2_FPSLIMITER_H
