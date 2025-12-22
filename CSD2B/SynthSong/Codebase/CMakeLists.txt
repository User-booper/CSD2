cmake_minimum_required(VERSION 3.22)
project(Codebase VERSION 0.0.1)

juce_add_console_app(Codebase PRODUCT_NAME "Codebase")
target_sources(Codebase PRIVATE main.cpp uiUtilities.cpp sine.cpp square.cpp oscillator.cpp synth.cpp additivesynth.cpp organsynth.cpp
  fmsynth.cpp melody.cpp note.cpp callback.cpp)
target_compile_definitions(Codebase PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(Codebase
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(Codebase PRIVATE cxx_std_20)





