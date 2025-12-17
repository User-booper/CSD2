cmake_minimum_required(VERSION 3.22)
project(MelodyTest VERSION 0.0.1)

juce_add_console_app(MelodyTest PRODUCT_NAME "MelodyTest")
target_sources(MelodyTest PRIVATE main.cpp square.cpp oscillator.cpp synth.cpp organsynth.cpp melody.cpp note.cpp callback.cpp)
target_compile_definitions(MelodyTest PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(MelodyTest
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(MelodyTest PRIVATE cxx_std_20)





