#pragma once

#include <JuceHeader.h>

namespace DMDA {
	class PluginProcessor;

	enum class Vst3Result : int32_t {
		OK = 0,
		ERROR = -1
	};

	class Vst3Extensions : public juce::VST3ClientExtensions {
	public:
		Vst3Extensions() = delete;
		explicit Vst3Extensions(PluginProcessor* processor);

		int32_t queryIAudioProcessor(const Steinberg::TUID, void** obj) override;

	private:
		PluginProcessor* const processor = nullptr;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Vst3Extensions)
	};
}
