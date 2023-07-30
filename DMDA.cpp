#include "DMDA.h"

#include "Context.cpp"
#include "MidiFileContext.cpp"

#if DMDA_PLUGIN

#include "PluginProcessor.cpp"
#include "PluginExtensions.cpp"

#else // DMDA_PLUGIN

#include "PluginVisitor.cpp"

#endif // DMDA_PLUGIN
