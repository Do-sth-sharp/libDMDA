#include "DMDA.h"

#if DMDA_PLUGIN

#include "PluginProcessor.cpp"
#include "PluginExtensions.cpp"

#else // DMDA_PLUGIN

#include "PluginVisitor.cpp"

#endif // DMDA_PLUGIN
