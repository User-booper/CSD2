cmake_minimum_required(VERSION 3.22)
project(Organ_MelodyTest VERSION 0.0.1)

juce_add_console_app(Organ_MelodyTest PRODUCT_NAME "Organ_MelodyTest")
target_sources(Organ_MelodyTest PRIVATE main.cpp square.cpp oscillator.cpp synth.cpp organsynth.cpp melody.cpp note.cpp callback.cpp)
target_compile_definitions(Organ_MelodyTest PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(Organ_MelodyTest
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(Organ_MelodyTest PRIVATE cxx_std_20)





