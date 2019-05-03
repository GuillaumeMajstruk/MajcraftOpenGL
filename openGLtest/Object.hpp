//
// Created by m416099 on 03/05/2019.
//

#ifndef MAJCRAFT2_OBJECT_HPP
#define MAJCRAFT2_OBJECT_HPP


#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm.hpp>
#include "ObjLoader.h"

using namespace std;

class Object {
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


#endif //MAJCRAFT2_OBJECT_HPP
