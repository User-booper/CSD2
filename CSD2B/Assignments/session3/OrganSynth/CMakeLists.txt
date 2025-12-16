cmake_minimum_required(VERSION 3.22)
project(OrganSynth VERSION 0.0.1)

juce_add_console_app(OrganSynth PRODUCT_NAME "OrganSynth")
target_sources(OrganSynth PRIVATE main.cpp square.cpp oscillator.cpp synth.cpp)
target_compile_definitions(OrganSynth PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(OrganSynth
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(OrganSynth PRIVATE cxx_std_20)





