cmake_minimum_required(VERSION 3.22)
project(UI_Utils_Test VERSION 0.0.1)

juce_add_console_app(UI_Utils_Test PRODUCT_NAME "UI_Utils_Test")
target_sources(UI_Utils_Test PRIVATE main.cpp sine.cpp oscillator.cpp)
target_compile_definitions(UI_Utils_Test PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(UI_Utils_Test
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(UI_Utils_Test PRIVATE cxx_std_20)





