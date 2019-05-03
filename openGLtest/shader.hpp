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

    void    setInt(const std::string &locationName, int i)
    {
        glUniform1i(glGetUniformLocation(this->m_ID, locationName.c_str()), i);
    }

    void    setFloat(const std::string &locationName, float i)
    {
        glUniform1f(glGetUniformLocation(this->m_ID, locationName.c_str()), i);
    }

    void    setVec2(const std::string &locationName, float x, float y)
    {
        glUniform2f(glGetUniformLocation(this->m_ID, locationName.c_str()), x, y);
    }

    void    setVec2(const std::string &locationName, const glm::vec2 &vec)
    {
        glUniform2fv(glGetUniformLocation(this->m_ID, locationName.c_str()), 1, &vec[0]);
    }

    void    setVec3(const std::string &locationName, float x, float y, float z)
    {
        glUniform3f(glGetUniformLocation(this->m_ID, locationName.c_str()), x, y, z);
    }

    void    setVec3(const std::string &locationName, const glm::vec3 &vec)
    {
        glUniform3fv(glGetUniformLocation(this->m_ID, locationName.c_str()), 1, &vec[0]);
    }

    void    setMat2(const std::string &locationName, const glm::mat2 &mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(this->m_ID, locationName.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void    setMat3(const std::string &locationName, const glm::mat3 &mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(this->m_ID, locationName.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void    setMat4(const std::string &locationName, const glm::mat4 &mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(this->m_ID, locationName.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void    use()
    {
        glUseProgram(m_ID);
    }

    GLuint  m_ID;
    GLuint  vShader;
    GLuint  fShader;
};
#endif //SHADER_HPP
