/*****************************************************************//**
 * \file    DMDA.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 * 
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Dec 2023
 * \version 1.2.2
 * \license	MIT License
 *********************************************************************/

#pragma once

#include "Macros.h"
#include "Context.h"
#include "MidiFileContext.h"

#define DMDA_VERSION "1.2.2"

#if DMDA_PLUGIN

#include "PluginProcessor.h"

#else // DMDA_PLUGIN

#include "PluginVisitor.h"

#endif // DMDA_PLUGIN
