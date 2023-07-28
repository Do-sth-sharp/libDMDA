#pragma once

#include <JuceHeader.h>
#include "Context.h"
#include "PluginExtensions.h"

namespace DMDA {
	class PluginProcessor : public juce::AudioProcessor{
	public:
		PluginProcessor();
		PluginProcessor(
			const juce::AudioProcessor::BusesProperties& ioLayouts);
		PluginProcessor(
			const std::initializer_list<const short[2]>& channelLayoutList);
		virtual ~PluginProcessor() override = default;

		juce::VST3ClientExtensions* getVST3ClientExtensions() override;

	protected:
		friend class Vst3Extensions;
		Context* getContext() const;
		virtual Context* createContext() const;

	private:
		std::unique_ptr<Context> context = nullptr;
		std::unique_ptr<Vst3Extensions> vst3Extensions = nullptr;

		void initContext();

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
	};
}
