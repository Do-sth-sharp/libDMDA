# libDMDA(Deprecated)
Directly Musical Data Access library for VST3 with JUCE.

> [!CAUTION]
> Deprecated: [ARA](https://github.com/Celemony/ARA_SDK) with [ARAExtension](https://github.com/Do-sth-sharp/ARAExtension) has been used in [VocalShaper](https://github.com/Do-sth-sharp/VocalShaper) instead of DMDA to pass Musical Contexts to plugins.

## Use
1. Add [VST3 SDK](https://github.com/steinbergmedia/vst3sdk) and [JUCE](https://github.com/juce-framework/JUCE) in your project.
2. Include `DMDA.h` then link `DMDA.cpp` in your host or plugin.

### For plugin
- Set the `DMDA_PLUGIN` macro to `1` in your build system.
- Create your plugin processor class inherit from the `PluginProcessor` class.
- Init the DMDA context in the constructor of your processor class.

### For host
- Use the `PluginVisitor` or `PluginHandler` to visit the DMDA context in the plugin.

## Demos
- [SynthEngineDemo](https://github.com/Do-sth-sharp/SynthEngineDemo)(Deprecated)
