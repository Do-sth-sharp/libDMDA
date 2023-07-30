#pragma once

#include <JuceHeader.h>
#include "Context.h"

namespace DMDA {
	class MidiFileContext : public Context {
	public:
		MidiFileContext() = default;

		juce::MidiFile& getData();
		juce::ReadWriteLock& getLock() const;

	private:
		juce::MidiFile data;
		mutable juce::ReadWriteLock lock;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiFileContext)
	};
}
