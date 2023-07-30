/*****************************************************************//**
 * \file    DMDA.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#include "DMDA.h"

#include "Context.cpp"
#include "MidiFileContext.cpp"

#if DMDA_PLUGIN

#include "PluginProcessor.cpp"
#include "PluginExtensions.cpp"

#else // DMDA_PLUGIN

#include "PluginVisitor.cpp"

#endif // DMDA_PLUGIN
