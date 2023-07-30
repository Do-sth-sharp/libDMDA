#pragma once

#include "Macros.h"
#include "Context.h"
#include "MidiFileContext.h"

#if DMDA_PLUGIN

#include "PluginProcessor.h"

#else // DMDA_PLUGIN

#include "PluginVisitor.h"

#endif // DMDA_PLUGIN
