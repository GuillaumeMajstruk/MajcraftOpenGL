//
//  ObjLoader.h
//  openGLtest
//
//  Created by gmajstru on 28/04/2019.
//  Copyright © 2019 Guillaume Majstruk. All rights reserved.
//

#ifndef ObjLoader_h
#define ObjLoader_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#ifdef __APPLE__
    #include <boost/algorithm/string.hpp>
#else
    #include <boost/algorithm/string.hpp>
#endif
#include <vector>
#include <algorithm>

class ObjLoader {
public:
    
    ObjLoader (const std::string &FileName)
    {
        std::string path = "./Models/" + FileName + ".obj";
        std::ifstream fileBuffer;
        std::string line;
        unsigned int buffSize = 0;
        m_vertex_num = 0;
        std::vector<float> vertice_coords;
        std::vector<float> texture_coords;
        std::vector<float> normals_coords;
        std::vector<float> model;
        
        fileBuffer.open(path.c_str());
        if (!fileBuffer.is_open())
        {
            std::cout << "ERROR::OPENING_FILE" << std::endl;
            throw std::exception();
        }
        while (std::getline(fileBuffer, line))
            buffSize++;
        fileBuffer.close();
        fileBuffer.open(path.c_str());
        if (!fileBuffer.is_open())
        {
            std::cout << "ERROR::OPENING_FILE" << std::endl;
            throw std::exception();
        }
        while (std::getline(fileBuffer, line))
        {
            if (boost::starts_with(line, "#"))
                continue;
            if (boost::starts_with(line, "v "))
            {
                boost::trim_left_if(line, boost::is_any_of("v "));
                std::vector<std::string> verticeCoords;
                boost::split(verticeCoords, line, boost::is_any_of(" "));
                for (int i = 0; i < verticeCoords.size(); i++)
                    vertice_coords.push_back(atof(verticeCoords[i].c_str()));
            }
            if (boost::starts_with(line, "vt "))
            {
                boost::trim_left_if(line, boost::is_any_of("vt "));
                std::vector<std::string> textCoords;
                boost::split(textCoords, line, boost::is_any_of(" "));
                for (int i = 0; i < textCoords.size(); i++)
                    texture_coords.push_back(atof(textCoords[i].c_str()));
            }
            if (boost::starts_with(line, "vn "))
            {
                boost::trim_left_if(line, boost::is_any_of("vn "));
                std::vector<std::string> normCoords;
                boost::split(normCoords, line, boost::is_any_of(" "));
                for (int i = 0; i < normCoords.size(); i++)
                    normals_coords.push_back(atof(normCoords[i].c_str()));
            }
            if (boost::starts_with(line, "f "))
            {
                boost::trim_left_if(line, boost::is_any_of("f "));
                std::vector<std::string> assy;
                boost::split(assy, line, boost::is_any_of(" "));
                std::vector<std::string> split;
                m_vertex_num += assy.size();
                for (int i = 0; i < assy.size(); i++)
                {
                    // to have -> [v / vt / vn]
                    boost::split(split, assy[i], boost::is_any_of("/"));
                    //vertices coordinates
                    for (int x = (atoi(split[0].c_str()) - 1) * 3; x < ((atoi(split[0].c_str()) - 1) * 3) + 3; x++)
                        model.push_back(vertice_coords[x]);
                    //texture coordinates
                    for (int x = (atoi(split[1].c_str()) - 1) * 2; x < ((atoi(split[1].c_str()) - 1) * 2) + 2; x++)
                        model.push_back(texture_coords[x]);
                }
            }
        }
        fileBuffer.close();
        std::cout << m_vertex_num << std::endl;
        m_vertex_array_len = model.size();
        if (!(m_vertex_array = (float*)malloc(sizeof(float) * m_vertex_array_len)))
        {
            std::cout << "error mallocing model table" << std::endl;
            throw std::exception();
        }
        std::copy(model.begin(), model.end(), m_vertex_array);
    }
    
    ~ObjLoader ()
    {
        free(m_vertex_array);
    }
    
public:
    float           *m_vertex_array;
    float           m_vertex_array_len;
    unsigned int    m_vertex_num;
};

#endif /* ObjLoader_h */
