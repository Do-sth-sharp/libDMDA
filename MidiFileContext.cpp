/*****************************************************************//**
 * \file    MidiFileContext.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#include "MidiFileContext.h"

namespace DMDA {
	juce::MidiFile& MidiFileContext::getData() {
		return this->data;
	}

	juce::ReadWriteLock& MidiFileContext::getLock() const {
		return this->lock;
	}
}
