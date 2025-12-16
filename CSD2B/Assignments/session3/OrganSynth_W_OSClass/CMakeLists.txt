cmake_minimum_required(VERSION 3.22)
project(OrganSynth_W_OSClass VERSION 0.0.1)

juce_add_console_app(OrganSynth_W_OSClass PRODUCT_NAME "OrganSynth_W_OSClass")
target_sources(OrganSynth_W_OSClass PRIVATE main.cpp square.cpp oscillator.cpp synth.cpp organsynth.cpp)
target_compile_definitions(OrganSynth_W_OSClass PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(OrganSynth_W_OSClass
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(OrganSynth_W_OSClass PRIVATE cxx_std_20)





