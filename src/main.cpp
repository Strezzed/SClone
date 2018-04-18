#include <iostream>

#include "SWindow.h"

int main()
{
    SWindow *window = new SWindow(1280, 720, "MC Clone | Pre Alpha", false, false);
    window->Create();

    while (!glfwWindowShouldClose(window->GetWindow()))
    {
        window->Render();
        window->PollEvents();
    }

    window->Destory();

    return EXIT_SUCCESS;
}