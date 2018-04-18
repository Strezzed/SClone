//
// Created by Keirb on 18/04/2018.
//

#include "SWindow.h"

SWindow::SWindow(int width, int height, const char *windowTitle, bool fullscreen, bool vsync)
{
    m_windowWidth = width;
    m_windowHeight = height;
    m_oldWindowWidth = m_windowWidth;
    m_oldWindowHeight = m_windowHeight;

    m_fullscreen = fullscreen;
    m_vsync = vsync;

    m_windowTitle = windowTitle;

    m_cursorX = 0;
    m_cursorY = 0;
    m_oldCursorX = m_cursorX;
    m_oldCursorY = m_cursorY;
}

SWindow::~SWindow()
{

}

void SWindow::Create()
{
    /** Init GLFW **/
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    /** Init Render Prams **/
    int samples = 8;
    glfwWindowHint(GLFW_SAMPLES, samples);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    glGetIntegerv(GL_SAMPLES_ARB, &samples);

    m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle, NULL, NULL);
    if (!m_pWindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    InitGLFWWindow(m_pWindow);

    if (m_fullscreen)
    {
        ToggleFullScreen(true);
    }
}

void SWindow::Destory()
{
    glfwTerminate();

}

void SWindow::Update(float deltaTime)
{
    double x, y;
    glfwGetCursorPos(m_pWindow, &x, &y);

    m_cursorX = (int) floor(x);
    m_cursorY = (int) floor(y);
}

void SWindow::PollEvents()
{
    glfwPollEvents();

}

void SWindow::Render()
{
    glfwSwapBuffers(m_pWindow);

}

void WindowResizeCallback(GLFWwindow *window, int width, int height){};

void WindowCloseCallback(GLFWwindow *window){};

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){};

void CharacterCallback(GLFWwindow *window, unsigned int keyCode){};

void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods){};

void MouseScrollCallback(GLFWwindow *window, double x, double y){};

void SWindow::InitGLFWWindow(GLFWwindow *window)
{
    glfwSetWindowSizeCallback(window, WindowResizeCallback);
    glfwSetWindowCloseCallback(window, WindowCloseCallback);
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCharCallback(window, CharacterCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetScrollCallback(window, MouseScrollCallback);

    const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwGetWindowSize(window, &m_windowWidth, &m_windowHeight);
    glfwSetWindowPos(window, (videoMode->width - m_windowWidth) / 2, (videoMode->height - m_windowHeight) / 2);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(m_vsync);

    WindowResizeCallback(window, m_windowWidth, m_windowHeight);

    glfwShowWindow(window);
}


void SWindow::ResizeWindow(int width, int height)
{
    m_minimized = (width == 0 || height == 0);

    m_windowWidth = width;
    m_windowHeight = height;
}

void SWindow::ToggleFullScreen(bool fullscreen)
{
    if (fullscreen)
    {
        const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

        m_oldWindowWidth = m_windowWidth;
        m_oldWindowHeight = m_windowHeight;

        m_windowWidth = videoMode->width;
        m_windowHeight = videoMode->height;
    } else
    {
        m_windowWidth = m_oldWindowWidth;
        m_windowHeight = m_oldWindowHeight;
    }

    GLFWwindow *newWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle,
                                             fullscreen ? glfwGetPrimaryMonitor() : NULL, m_pWindow);

    InitGLFWWindow(newWindow);

    glfwDestroyWindow(m_pWindow);
    m_pWindow = newWindow;
}

GLFWwindow *SWindow::GetWindow()
{
    return m_pWindow;
}

int SWindow::GetWindowWidth()
{
    return m_windowWidth;
}

int SWindow::GetWindowHeight()
{
    return m_windowHeight;
}

bool SWindow::GetMinimized()
{
    return m_minimized;
}

int SWindow::GetCursorX()
{
    return m_cursorX;
}

int SWindow::GetCursorY()
{
    return m_cursorY;
}

void SWindow::SetCursorPosition(int x, int y)
{
    glfwSetCursorPos(m_pWindow, x, y);
}

