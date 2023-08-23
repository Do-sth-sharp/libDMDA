/*****************************************************************//**
 * \file    MidiFileContext.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Aug 2023
 * \version 1.1.0
 * \license	MIT License
 *********************************************************************/

#include "MidiFileContext.h"

namespace DMDA {
	const juce::MidiFile& MidiFileContext::getData() const {
		return this->data;
	}

	void MidiFileContext::setData(const juce::MidiFile& data) {
		this->data = data;
	}

	juce::ReadWriteLock& MidiFileContext::getLock() const {
		return this->lock;
	}
}
