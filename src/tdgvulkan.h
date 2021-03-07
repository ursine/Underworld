#pragma once

#include <vulkan/vulkan.h>
#include <string>
#include <ostream>
#include <sstream>

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


std::string versionAsString(const uint32_t version) {
    std::ostringstream out;
    out << VK_VERSION_MAJOR(version) << "." << VK_VERSION_MINOR(version) << "." << VK_VERSION_PATCH(version);
    return out.str();
}

class TDGApplicationInfo {
private:
    VkApplicationInfo appInfo{};

    // Holding on for dear life

public:
    TDGApplicationInfo() {
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.apiVersion = VK_API_VERSION_1_2;  // TODO: Code to figure out available version
    }

    [[nodiscard]] VkStructureType sType() const { return appInfo.sType; }
    [[nodiscard]] uint32_t apiVersion() const { return appInfo.apiVersion; }
    [[nodiscard]] std::string apiVersionAsStr() const { return versionAsString(appInfo.apiVersion); }

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

    [[nodiscard]] std::string applicationVersionAsStr() const {
        return versionAsString(appInfo.applicationVersion);
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

    // Application Versions
    [[nodiscard]] uint32_t engineVersion() const {
        return appInfo.engineVersion;
    }

    [[nodiscard]] std::string engineVersionAsStr() const {
        return versionAsString(appInfo.engineVersion);
    }

    TDGApplicationInfo& engineVersion(const int major, const int minor, const int patch) {
        appInfo.engineVersion = VK_MAKE_VERSION(major, minor, patch);
        return *this;
    }

    // TODO: This is temporary
    VkApplicationInfo* ptr() { return &appInfo; }
};


std::ostream& operator<<(std::ostream &os, const TDGApplicationInfo& foo)
{
    os << "TDGApplicationInfo{" <<
        "sType=" << foo.sType() << ", " <<
        "pNext=" << foo.next() << ", " <<
        "pApplicationName=" << foo.applicationName() << ", " <<
        "applicationVersion=" << foo.applicationVersionAsStr() << ", " <<
        "pEngineName=" << foo.engineName() << ", " <<
        "engineVersion=" << foo.engineVersionAsStr() << ", " <<
        "apiVersion=" << foo.apiVersionAsStr() << "}";
    return os;
}

