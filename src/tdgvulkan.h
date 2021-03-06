#pragma once

#include <vulkan/vulkan.h>
#include <string>
#include <ostream>

class TDGVulkan {
private:
    VkInstance instance;

public:
    TDGVulkan() {

    }

    ~TDGVulkan() {
        vkDestroyInstance(instance, nullptr);
    }
};

class TDGApplicationInfo {
private:
    VkApplicationInfo appInfo{};

    // Holding on for dear life

public:
    TDGApplicationInfo() {
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    }

    // Next
    [[nodiscard]] const void* next() const { return appInfo.pNext; }

    TDGApplicationInfo& next(const void* pNext) {
        appInfo.pNext = pNext;
        return *this;
    }

    // Application Name
    [[nodiscard]] std::string applicationName() const {
        return std::string(appInfo.pApplicationName);
    }

    TDGApplicationInfo& applicationName(const char* appName) {
        appInfo.pApplicationName = appName;
        return *this;
    }

    // Application Versions
    [[nodiscard]] uint32_t applicationVersion() const {
        return appInfo.applicationVersion;
    }

    TDGApplicationInfo& applicationVersion(const int major, const int minor, const int patch) {
        appInfo.applicationVersion = VK_MAKE_VERSION(major, minor, patch);
        return *this;
    }

    // Engine Name
    [[nodiscard]] std::string engineName() const {
        return std::string(appInfo.pEngineName);
    }

    TDGApplicationInfo& engineName(const char* engineName) {
        appInfo.pEngineName = engineName;
        return *this;
    }


    uint32_t           engineVersion;
    uint32_t           apiVersion;

    //
    //appInfo.pEngineName = "No Engine";
    //appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    //appInfo.apiVersion = VK_API_VERSION_1_0;
};

std::ostream& operator<<(std::ostream &os, const TDGApplicationInfo& foo)
{
    os << "TDGApplicationInfo{" << "}";
    return os;
}

