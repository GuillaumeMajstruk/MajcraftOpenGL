//
// Created by m416099 on 03/05/2019.
//

#ifndef MAJCRAFT2_DISPLAYMANAGER_HPP
#define MAJCRAFT2_DISPLAYMANAGER_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <glm.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#define SCR_WIDTH 600
#define SCR_HEIGHT 600

using namespace std;

class Window;

class Env {
public:
    Env ()
    {
        glfwInit();
        m_width = SCR_WIDTH;
        m_height = SCR_HEIGHT;
        m_deltatime = 0.0f;
        m_lastframe = 0.0f;
        m_xpos = 0;
        m_ypos = 0;
    }

    ~Env()
    {
        glfwTerminate();
    }

    GLuint m_width;
    GLuint m_height;
    GLfloat m_deltatime;
    GLfloat m_lastframe;
    GLdouble m_xpos;
    GLdouble m_ypos;
    const GLuint major_minor_openGL_ver = 3;
};

class Window {
public:
    Window(const string &name, const Env &env) {

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        if (!(m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, name.c_str(), nullptr, nullptr)))
        {
            cout << "Failed to create GLFW window\n" << endl;
            glfwTerminate();
            exit (EXIT_FAILURE);
        }
        glfwMakeContextCurrent(this->m_window);
        glfwSetFramebufferSizeCallback(this->m_window, framebuffer_size_callback);
        glfwSetInputMode(this->m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#ifndef __APPLE__
        glewInit();
#endif
    }

    GLFWwindow  *getWindow() const { return (this->m_window); }
private:
    GLFWwindow  *m_window;

    static void     framebuffer_size_callback(GLFWwindow *window, GLint width, GLint height)
    {
        cout << "window resized: " << width << " " << height << endl;
        glViewport(0, 0, width, height);
    }
};


#endif //MAJCRAFT2_DISPLAYMANAGER_HPP
