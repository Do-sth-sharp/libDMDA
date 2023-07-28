#include "PluginProcessor.h"

namespace DMDA {
	PluginProcessor::PluginProcessor()
		: AudioProcessor() {}
	PluginProcessor::PluginProcessor(
		const juce::AudioProcessor::BusesProperties& ioLayouts)
		: AudioProcessor(ioLayouts) {}
	PluginProcessor::PluginProcessor(
		const std::initializer_list<const short[2]>& channelLayoutList)
		: AudioProcessor(channelLayoutList) {}

	juce::VST3ClientExtensions* PluginProcessor::getVST3ClientExtensions() {
		return this->vst3Extensions.get();
	}

	Context* PluginProcessor::getContext() const {
		return this->context.get();
	}

	void PluginProcessor::initContext() {
		this->context = std::make_unique<Context>();
		this->vst3Extensions = std::make_unique<Vst3Extensions>(this);
	}
}
