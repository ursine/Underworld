find_package(Vulkan REQUIRED FATAL_ERROR)
#find_package(glfw3 REQUIRED FATAL_ERROR)

add_executable(vulkantest main.cpp tdgvulkan.h tdgvkdebug.h)
target_link_libraries (vulkantest glfw Vulkan::Vulkan)
target_include_directories (vulkantest PUBLIC ${Vulkan_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS})
