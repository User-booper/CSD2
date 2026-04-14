cmake_minimum_required(VERSION 3.23)
project(codebase_CF VERSION 0.0.1)

add_subdirectory(csd_lib)

if(MSVC)
    find_package(liblo CONFIG REQUIRED)
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBLO REQUIRED IMPORTED_TARGET liblo)
endif()



juce_add_console_app(codebase_CF PRODUCT_NAME "codebase_CF")
target_sources(codebase_CF PRIVATE main.cpp callback.cpp)
target_compile_definitions(codebase_CF PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(codebase_CF PRIVATE ${LIBLO_INCLUDE_DIR})

if(MSVC)  
target_link_libraries(codebase_CF PRIVATE
        csd_lib
        liblo::liblo
        #liblo::liblo-static

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #juce::juce_recommended_warning_flags
)
else()
    target_link_libraries(codebase_CF PRIVATE
        csd_lib

        PkgConfig::LIBLO 

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #juce::juce_recommended_warning_flags
)
endif()
target_compile_features(codebase_CF PRIVATE cxx_std_20)
