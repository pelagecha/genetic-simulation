#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/** Handle window resizing */
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  

/** Handle input */
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    // Init GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Set GLFW version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // forward-compatibility (non-core)

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Genetic Algorithm v0.1", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // Make context current

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600); // setup viewport settings (can render inside/outside the window)
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Register framebuffer (window resizing) callback

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        /*
         * RENDER LOGIC START
         */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        /*
         * RENDER LOGIC END
         */
        // Swap buffers and poll events
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
