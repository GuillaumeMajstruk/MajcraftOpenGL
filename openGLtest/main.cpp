#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #define GLEW_STATIC
    #include <GL/glew.h>
#endif
#include <iostream>
#include <GLFW/glfw3.h>
#include "Librairies/glm/glm.hpp"
#include "Librairies/glm/gtc/type_ptr.hpp"
#include "Librairies/glm/gtc/matrix_transform.hpp"
#include <string>
#include "shader.hpp"
#include "stb_image.h"
#include "ObjLoader.h"

using namespace std;

class Window;

class Env {
public:
    Env (GLuint i_w, GLuint i_h):
        m_width(i_w),
        m_height(i_h)
    {
        glfwInit();
    }

    ~Env()
    {
        glfwTerminate();
    }

    GLuint m_width;
    GLuint m_height;
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

        if (!(m_window = glfwCreateWindow(env.m_width, env.m_height, name.c_str(), nullptr, nullptr)))
        {
            cout << "Failed to create GLFW window\n" << endl;
            glfwTerminate();
            exit (EXIT_FAILURE);
        }
        glfwMakeContextCurrent(this->m_window);
        glfwSetFramebufferSizeCallback(this->m_window, framebuffer_size_callback);
#ifndef __APPLE__
        glewInit();
#endif
    }

    GLFWwindow  *getWindow() const { return (this->m_window); }

    void            processKeyboardInput()
    {
        if (glfwGetKey(this->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(this->m_window, GL_TRUE);
        }
    }
private:
    GLFWwindow  *m_window;

    static void     framebuffer_size_callback(GLFWwindow *window, GLint width, GLint height)
    {
        cout << "window resized: " << width << " " << height << endl;
        glViewport(0, 0, width, height);
    }
};

class Object
{
public:
    Object (const string &objToLoad)
    {
        ObjLoader *loader = new ObjLoader(objToLoad);
        
        m_buffer_len = loader->m_vertex_array_len;
        m_vToDraw = loader->m_vertex_num;
        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
        glBindVertexArray(m_vao);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(loader->m_vertex_array) * m_buffer_len, loader->m_vertex_array, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        
        int w, h, chan;
#ifdef __APPLE__
        unsigned char   *texture_data = stbi_load("/Users/guillaume/Desktop/openGLtest/openGLtest/crate.jpg", &w, &h, &chan, 0);
#else
        unsigned char *texture_data = stbi_load("./crate.jpg", &w, &h, &chan, 0);
#endif
        if (!texture_data)
        {
            cout << "ERROR LOADING TEXTURE FILE" << endl;
        }
        
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(texture_data);
        delete loader;
    }
    
    void    draw()
    {
        glBindTexture(GL_TEXTURE_2D, this->m_texture);
        glBindVertexArray(this->m_vao);
        glDrawArrays(GL_TRIANGLES, 0, m_vToDraw);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    GLuint  m_vao, m_vbo;
    GLuint  m_texture;
    GLuint  m_buffer_len;
    GLuint  m_vToDraw;
};

int main(int argc, char **argv)
{
    Env *env = new Env(1000, 1000);
    Window *window = new Window("Majcraft", *env);
    Shader *shader = new Shader(
            "./Shaders/cubeVertex.vs",
            "./Shaders/cubeFragment.fs"
            );
    glEnable(GL_DEPTH_TEST);
    Object *o = new Object("monkey2");
    
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(25.0f), (float)(env->m_width / env->m_height), 0.1f, 100.0f);

    shader->use();
    GLint viewLoc = glGetUniformLocation(shader->m_ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    GLint projLoc = glGetUniformLocation(shader->m_ID, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    while (!glfwWindowShouldClose(window->getWindow()))
    {
        window->processKeyboardInput();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        shader->use();
        GLint modelLoc = glGetUniformLocation(shader->m_ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        o->draw();
        glfwSwapBuffers(window->getWindow());
        glfwPollEvents();
    }
    delete shader;
    delete window;
    delete env;
    delete o;
    return 0;
}
