//
// Created by Keirb on 18/04/2018.
//

#ifndef OPENGLTEMPLATE_SWINDOW_H
#define OPENGLTEMPLATE_SWINDOW_H

#include <GL/glew.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <GLFW/glfw3.h>

class SWindow
{
public:
    /** Public Memebers **/
protected:
    /** Protected Memebers **/
private:
    /** Private Memebers **/

    GLFWwindow *m_pWindow;

    const char *m_windowTitle;

    // Window Size/Dimensions
    int m_windowWidth;
    int m_windowHeight;
    int m_oldWindowWidth;
    int m_oldWindowHeight;

    // If Minimized
    bool m_minimized;

    bool m_fullscreen;

    bool m_vsync;

    // Cursor Position
    int m_cursorX;
    int m_cursorY;
    int m_oldCursorX;
    int m_oldCursorY;

public:
    /** Public Methods **/

    SWindow(int width, int height, const char *windowTitle, bool fullscreen, bool vsync);

    ~SWindow();

    void Create();

    void Destory();

    void Update(float deltaTime);

    void PollEvents();

    void Render();

    void InitGLFWWindow(GLFWwindow *window);

    void ResizeWindow(int width, int height);

    void ToggleFullScreen(bool fullscreen);

    /** Getters & Setters **/

    GLFWwindow *GetWindow();

    // Window Size/Dimensions
    int GetWindowWidth();

    int GetWindowHeight();

    // Is Minimized
    bool GetMinimized();

    // Cursor X,Y
    int GetCursorX();

    int GetCursorY();

    void SetCursorPosition(int x, int y);


protected:
    /** Protected Methods **/
private:
    /** Private Methods **/

};


#endif //OPENGLTEMPLATE_SWINDOW_H
