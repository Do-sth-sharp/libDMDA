/*****************************************************************//**
 * \file    DMDA.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 * 
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Jan 2024
 * \version 1.2.3
 * \license	MIT License
 *********************************************************************/

#pragma once

#include "Macros.h"
#include "Context.h"
#include "MidiFileContext.h"

#define DMDA_VERSION "1.2.3"

#if DMDA_PLUGIN

#include "PluginProcessor.h"

#else // DMDA_PLUGIN

#include "PluginVisitor.h"

#endif // DMDA_PLUGIN
