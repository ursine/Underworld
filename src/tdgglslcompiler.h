#pragma once

#include <vulkan/vulkan.h>


class TDGVkGlSlCompiler {

    const glslang_input_t input =
            {
                    .language = GLSLANG_SOURCE_GLSL,
                    .stage = GLSLANG_STAGE_VERTEX,
                    .client = GLSLANG_CLIENT_VULKAN,
                    .client_version = GLSLANG_TARGET_VULKAN_1_1,
                    .target_language = GLSLANG_TARGET_SPV,
                    .target_language_version = GLSLANG_TARGET_SPV_1_3,
                    .code = shaderCodeVertex,
                    .default_version = 100,
                    .default_profile = GLSLANG_NO_PROFILE,
                    .force_default_version_and_profile = false,
                    .forward_compatible = false,
                    .messages = GLSLANG_MSG_DEFAULT_BIT,
                    .resource = &glslang::DefaultTBuiltInResource,
            };

    TDGVkGlSlCompiler() {
        glslang_initialize_process();
    }

};