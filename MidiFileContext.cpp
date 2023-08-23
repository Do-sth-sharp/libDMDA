/*****************************************************************//**
 * \file    MidiFileContext.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Aug 2023
 * \version 1.2.1
 * \license	MIT License
 *********************************************************************/

#include "MidiFileContext.h"

namespace DMDA {
	const juce::MidiFile* MidiFileContext::getData() const {
		return this->ptrData;
	}

	void MidiFileContext::setData(const juce::MidiFile* data) {
		this->ptrData = data;
	}

	juce::ReadWriteLock& MidiFileContext::getLock() const {
		return this->lock;
	}
}
