#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#else
    #define GLEW_STATIC
    #include <GL/glew.h>
#endif
#include "Librairies/glm/glm.hpp"
class Shader
{

public:

    Shader(const char *vertexShader, const char *fragmentShader)
    {
        printf("Supported GLSL version is %s.\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
        std::string vertexData;
        std::string fragmentData;
        std::ifstream vertexFile;
        std::ifstream fragmentFile;

        vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vertexFile.open(vertexShader);
            fragmentFile.open(fragmentShader);
            std::stringstream vertexReader, fragmentReader;
            vertexReader << vertexFile.rdbuf();
            fragmentReader << fragmentFile.rdbuf();
            vertexFile.close();
            fragmentFile.close();
            vertexData = vertexReader.str();
            fragmentData = fragmentReader.str();
        }
        catch (std::ifstream::failure &e)
        {
            std::cout << "ERROR::LOADING_SHADER" << std::endl << e.what() << e.code() << std::endl;
        }
        char const  *vertexCode = vertexData.c_str();
        char const  *fragmentCode = fragmentData.c_str();

        vShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vShader, 1, &vertexCode, nullptr);
        glCompileShader(vShader);
        GLint success;
        char info[512];
        glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vShader, 512, nullptr, info);
            std::cout << "ERROR::SHADER::VERTEX::FAILED_TO_COMPILE\n" << info << std::endl;
        } else
            std::cout << "vertex shader successfully compiled" << std::endl;

        fShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fShader, 1, &fragmentCode, nullptr);
        glCompileShader(fShader);
        glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fShader, 512, nullptr, info);
            std::cout << "ERROR::SHADER::FRAGMENT::FAILED_TO_COMPILE\n" << info << std::endl;
        } else
            std::cout << "fragment shader successfully compiled" << std::endl;

        m_ID = glCreateProgram();
        glAttachShader(m_ID, vShader);
        glAttachShader(m_ID, fShader);
        glLinkProgram(m_ID);
        glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_ID, 512, nullptr, info);
            std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << info << std::endl;
        }
        else
        {
            glDeleteShader(vShader);
            glDeleteShader(fShader);
            std::cout << "program successfully linked with shaders" << std::endl;
        }
    }

    void use()
    {
        glUseProgram(m_ID);
    }

    GLuint  m_ID;
    GLuint  vShader;
    GLuint  fShader;

private:

//    void compileShader(GLuint shader, GLenum ShaderType, char const *shaderSource)
//    {
//        shader = glCreateShader(ShaderType);
//        glShaderSource(shader, 1, &shaderSource, nullptr);
//        glCompileShader(shader);
//
//        GLint success = 0;
//        GLuint buffsize = 512;
//        char info[buffsize];
//        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//        if (!success)
//        {
//            glGetShaderInfoLog(shader, buffsize, nullptr, info);
//            if (ShaderType == GL_VERTEX_SHADER)
//                std::cout << "ERROR::SHADER::VERTEX::FAILED_TO_COMPILE\n" << info << std::endl;
//            else
//                std::cout << "ERROR::SHADER::FRAGMENT::FAILED_TO_COMPILE\n" << info << std::endl;
//        }
//        else
//        {
//            if (ShaderType == GL_VERTEX_SHADER)
//                std::cout << "vertex shader successfully compiled" << std::endl;
//            else
//                std::cout << "fragment shader successfully compiled" << std::endl;
//        }
//    }
//
//    void createShaderProgram()
//    {
//        m_ID = glCreateProgram();
//        glAttachShader(m_ID, vShader);
//        glAttachShader(m_ID, fShader);
//        glLinkProgram(m_ID);
//        GLint success;
//        GLuint buffsize = 512;
//        char info[buffsize];
//
//        glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
//        if (!success)
//        {
//            glGetProgramInfoLog(m_ID, buffsize, nullptr, info);
//            std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << info << std::endl;
//        }
//        else
//        {
//            std::cout << "program successfully linked with shaders" << std::endl;
//        }
//    }
};
#endif //SHADER_HPP
