#pragma once

#include <JuceHeader.h>

namespace DMDA {
	class Context {
	public:
		Context() = default;
		virtual ~Context() = default;

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Context)
	};
}