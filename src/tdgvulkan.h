#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <ostream>
#include <sstream>

namespace tdg {

    std::string versionAsString(const uint32_t version) {
        std::ostringstream out;
        out << VK_VERSION_MAJOR(version) << "." << VK_VERSION_MINOR(version) << "." << VK_VERSION_PATCH(version);
        return out.str();
    }

    template<typename T>
    void clear(T* obj) {
        memset(obj, 0, sizeof(T));
    }

    struct ApplicationInfo : public ::VkApplicationInfo {
        ApplicationInfo() : VkApplicationInfo() {
            clear(this);
            sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            apiVersion = VK_API_VERSION_1_1;
        }

        [[nodiscard]] std::string applicationVersionString() const {
            return versionAsString(applicationVersion);
        }

        ApplicationInfo* setApplicationVersion(const int major, const int minor, const int patch) {
            applicationVersion = VK_MAKE_VERSION(major,minor,patch);
            return this;
        }

        [[nodiscard]] std::string engineVersionString() const {
            return versionAsString(engineVersion);
        }

        ApplicationInfo* setEngineVersion(const int major, const int minor, const int patch) {
            engineVersion = VK_MAKE_VERSION(major,minor,patch);
            return this;
        }

        [[nodiscard]] std::string apiVersionString() const {
            return versionAsString(apiVersion);
        }
    };

    static_assert(sizeof(ApplicationInfo)==sizeof(::VkApplicationInfo));

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    class GLFWHost {
    private:
        GLFWwindow* window;

    public:
        GLFWHost() {
            glfwInit();   // Initialize the windowing system
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Don't make an OpenGL context
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Don't allow resizing

            // Create a window to do the work in
            window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        }

        ~GLFWHost() {
            glfwDestroyWindow(window);
            glfwTerminate();
        }

        void loop() {
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }
    };

}


std::ostream &operator<<(std::ostream &os, const tdg::ApplicationInfo &foo) {
    os << "tdg::ApplicationInfo{" <<
       "pApplicationName=\"" << foo.pApplicationName << "\", " <<
       "applicationVersion=" << foo.applicationVersionString() << ", " <<
       "pEngineName=\"" << foo.pEngineName << "\", " <<
       "engineVersion=" << foo.engineVersionString() << ", " <<
       "apiVersion=" << foo.apiVersionString() << "}";
    return os;
}

