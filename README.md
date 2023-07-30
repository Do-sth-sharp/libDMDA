# libDMDA
Directly Musical Data Access library for VST3 with JUCE.

## Use
1. Add [VST3 SDK](https://github.com/steinbergmedia/vst3sdk) and [JUCE](https://github.com/juce-framework/JUCE) in your project.
2. Include `DMDA.h` then link `DMDA.cpp` in your host or plugin.

### For plugin
- Set the `DMDA_PLUGIN` macro to `1` in your build system.
- Create your plugin processor class inherit from the `PluginProcessor` class.

### For host
- Use the `PluginVisitor` or `PluginHandler` to visit the DMDA context in the plugin.

## Demos
- [SynthEngineDemo](https://github.com/Do-sth-sharp/SynthEngineDemo)
