/*****************************************************************//**
 * \file    PluginExtensions.h
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

#include "Macros.h"

namespace DMDA {
	class PluginProcessor;

	enum class DMDA_API Vst3Result : int32_t {
		OK = 0,
		ERROR = -1
	};

	class DMDA_API Vst3Extensions : public juce::VST3ClientExtensions {
	public:
		Vst3Extensions() = delete;
		explicit Vst3Extensions(PluginProcessor* processor);

		int32_t queryIAudioProcessor(const Steinberg::TUID, void** obj) override;

	private:
		PluginProcessor* const processor = nullptr;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Vst3Extensions)
	};
}
