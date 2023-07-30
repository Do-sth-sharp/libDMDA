/*****************************************************************//**
 * \file    PluginProcessor.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

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

	Context* PluginProcessor::createContext() const {
		return new Context;
	}

	void PluginProcessor::initContext() {
		this->context = std::unique_ptr<Context>(this->createContext());
		this->vst3Extensions = std::make_unique<Vst3Extensions>(this);
	}
}
