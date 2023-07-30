#include "MidiFileContext.h"

namespace DMDA {
	juce::MidiFile& MidiFileContext::getData() {
		return this->data;
	}

	juce::ReadWriteLock& MidiFileContext::getLock() const {
		return this->lock;
	}
}
