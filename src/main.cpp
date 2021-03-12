#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "tdgvulkan.h"
#include "vulkan/vulkan.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
private:
    tdg::GLFWHost window;
    VkInstance instance;

public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initWindow() {
        // Handled By GLFWHost
    }

    void initVulkan() {
        createInstance();
    }

    void createInstance() {
        tdg::ApplicationInfo appInfo;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.setApplicationVersion(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.setEngineVersion(1, 0, 0);
        std::cout << appInfo << std::endl;

        /*vk::InstanceCreateInfo createInfo;
        createInfo.setPApplicationInfo(&appInfo);

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.setEnabledExtensionCount(glfwExtensionCount);
        createInfo.setPpEnabledExtensionNames(glfwExtensions);
        createInfo.setEnabledLayerCount(0);*/
    }

    void mainLoop() {
        window.loop(); // Hnadled by GLFWHost
    }

    void cleanup() {
        // Handled by GLFWHost
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}