﻿/*****************************************************************//**
 * \file    PluginProcessor.h
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
#include "PluginExtensions.h"

namespace DMDA {
	/**
	 * The base class of DMDA Plugin.
	 * 
	 * Create your plugin processor class inherit from this class 
	 * then override the createContext() method to create your DMDA context object 
	 * like this:
	 * 
	 * @code
	 *	class MyPluginProcessor : public DMDA::PluginProcessor {
	 *	// ...
	 *	public:
	 *		DMDA::Context* createContext() const override {
	 *			return new DMDA::MidiFileContext;
	 *		};
	 *	// ...
	 *	};
	 * @endcode
	 * 
	 * And you should call initContext() method in your constructor to
	 * create the context.
	 */
	class DMDA_API PluginProcessor : public juce::AudioProcessor {
	public:
		PluginProcessor();
		PluginProcessor(
			const juce::AudioProcessor::BusesProperties& ioLayouts);
		PluginProcessor(
			const std::initializer_list<const short[2]>& channelLayoutList);
		virtual ~PluginProcessor() override = default;
		
		/**
		 * For internal use.
		 */
		juce::VST3ClientExtensions* getVST3ClientExtensions() override;

	protected:
		friend class Vst3Extensions;
		/**
		 * Get the DMDA context pointer.
		 */
		Context* getContext() const;
		/**
		 * Create the DMDA context object.
		 * 
		 * @return	The pointer of the DMDA context object.
		 *			DMDA library will manage the object automatically.
		 */
		virtual Context* createContext() const;

		/**
		 * Use this to init DMDA Context. You should call this in your
		 * constructor.
		 */
		void initContext();

	private:
		std::unique_ptr<Context> context = nullptr;
		std::unique_ptr<Vst3Extensions> vst3Extensions = nullptr;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
	};
}
