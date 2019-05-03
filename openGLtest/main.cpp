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
#include "Object.hpp"
#include "DisplayManager.hpp"
#include "camera.hpp"

using namespace std;

class Camera;

template <class T>
void delete_item(T *an_item)
{
    cout << "deleting item" << endl;
    delete an_item;
}

void processKeyInput(GLFWwindow *win);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

//class Camera
//{
//public:
//    Camera (
//            const Env &env,
//            const GLfloat &fov = 45.0f,
//            const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 3.0f),
//            const glm::vec3 &lookingAt = glm::vec3(0.0f, 0.0f, 0.0f)
//                    )
//    {
//        camUp = glm::vec3(0.0f, 1.0f, 0.0f);
//        camFront = glm::vec3(0.0f, 0.0f, -1.0f);
//        camSpeed = 0.05f;
//        camNearPlane = 0.1f;
//        camFarPlane = 100.0f;
//        camPos = position;
//        camTarget = lookingAt;
//        camDir = glm::normalize(camPos - camTarget);
//        camRightdir = glm::normalize(glm::cross(camUp, camDir));
//        camUpdir = glm::normalize(glm::cross(camRightdir, camDir));
//        camViewMat = glm::lookAt(camPos, camPos + camFront, camUp);
//        camModelMat = glm::mat4(1.0f);
//        camFOV = fov;
//        camProjMat = glm::perspective(camFOV, (float)(env.m_width / env.m_height), camNearPlane, camFarPlane);
//        camPitch = 0.0f;
//        camYaw = 0.0f;
//    }
//
//    void    updateCam()
//    {
//        camViewMat = glm::lookAt(camPos, camPos + camFront, camUp);
//    }
//
//    glm::vec3   camPos;
//    glm::vec3   camDir;
//    glm::vec3   camUp;
//    glm::vec3   camFront;
//    glm::vec3   camUpdir;
//    glm::vec3   camRightdir;
//    glm::vec3   camTarget;
//
//    GLfloat     camPitch;
//    GLfloat     camYaw;
//    GLfloat     camSpeed;
//    GLfloat     camNearPlane;
//    GLfloat     camFarPlane;
//    GLfloat     camFOV;
//    glm::mat4   camViewMat;
//    glm::mat4   camModelMat;
//    glm::mat4   camProjMat;
//};

Camera cam(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main(int argc, char **argv)
{
    Env *env = new Env();
    Window *window = new Window("Majcraft", *env);

    Shader *shader = new Shader(
            "./Shaders/cubeVertex.vs",
            "./Shaders/cubeFragment.fs"
            );
    glEnable(GL_DEPTH_TEST);

    Object *o = new Object("monkey2");
    glfwSetCursorPosCallback(window->getWindow(), mouse_callback);
    glfwSetScrollCallback(window->getWindow(), scroll_callback);

    while (!glfwWindowShouldClose(window->getWindow()))
    {
        float currentFrame = glfwGetTime();
        env->m_deltatime = currentFrame - env->m_lastframe;
        env->m_lastframe = currentFrame;

        processKeyInput(window->getWindow());
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->use();
        glm::mat4 projection = glm::perspective(glm::radians(cam.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        shader->setMat4("projection", projection);
        glm::mat4 view = cam.GetViewMatrix();
        shader->setMat4("view", view);
        glm::mat4 model = glm::mat4(1.0f);
        shader->setMat4("model", model);
        o->draw();
        glfwSwapBuffers(window->getWindow());
        glfwPollEvents();
    }

    delete_item<Shader>(shader);
    delete_item<Window>(window);
    delete_item<Env>(env);
    delete_item<Object>(o);

    return 0;
}

void processKeyInput(GLFWwindow *win)
{
    cout << "moving" << endl;
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GL_TRUE);
    if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
        cam.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
        cam.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
        cam.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
        cam.ProcessKeyboard(RIGHT, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    cam.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cam.ProcessMouseScroll(yoffset);
}