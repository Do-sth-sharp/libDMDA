/*****************************************************************//**
 * \file    DMDA.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 * 
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#pragma once

#include "Macros.h"
#include "Context.h"
#include "MidiFileContext.h"

#if DMDA_PLUGIN

#include "PluginProcessor.h"

#else // DMDA_PLUGIN

#include "PluginVisitor.h"

#endif // DMDA_PLUGIN
