/*****************************************************************//**
 * \file    MidiFileContext.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Jan 2024
 * \version 1.2.3
 * \license	MIT License
 *********************************************************************/

#pragma once

#include <JuceHeader.h>
#include "Context.h"

namespace DMDA {
	/**
	 * The DMDA context with juce::MidiFile data.
	 */
	class DMDA_API MidiFileContext : public Context {
	public:
		MidiFileContext() = default;

		/**
		 * Get the reference of the data.
		 */
		const juce::MidiFile* getData() const;
		/**
		 * Set data.
		 */
		void setData(const juce::MidiFile* data);
		/**
		 * Get the reference of the read write lock.
		 */
		juce::ReadWriteLock& getLock() const;

	private:
		const juce::MidiFile* ptrData = nullptr;
		mutable juce::ReadWriteLock lock;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiFileContext)
	};
}
