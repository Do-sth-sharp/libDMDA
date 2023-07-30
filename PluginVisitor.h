/*****************************************************************//**
 * \file    PluginVisitor.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#pragma once

#include <JuceHeader.h>

namespace DMDA {
	class Context;

	/**
	 * The base for DMDA host to visit the plugin's DMDA context.
	 * 
	 * Inherit this class then implement the handleContext() method 
	 * to visit the context.
	 * 
	 * You can pass it to AudioPluginInstance::getExtensions() 
	 * then the handleContext() method could be invoked.
	 */
	class PluginVisitor : public juce::ExtensionsVisitor {
	public:
		virtual ~PluginVisitor() override = default;
		/**
		 * For internal use.
		 */
		void visitVST3Client(
			const juce::ExtensionsVisitor::VST3Client& client) override;

	protected:
		/**
		 * Handle the plugin's DMDA context.
		 */
		virtual void handleContext(Context*) = 0;

	private:
		JUCE_LEAK_DETECTOR(PluginVisitor)
	};

	/**
	 * Visit the plugin's DMDA context conveniently with lambda expression.
	 * 
	 * Create an instance of this with your lambda function 
	 * then pass the object to AudioPluginInstance::getExtensions() to invoke it.
	 * 
	 * @code
	 *	DMDA::PluginHandler handler([] (DMDA::Context* context) {
	 *		// Do sth. with the context.
	 *	});
	 *	thePluginInstance->getExtensions(handler);
	 * @endcode
	 */
	class PluginHandler final : public PluginVisitor {
	public:
		PluginHandler() = delete;
		PluginHandler(std::function<void(Context*)> function);

	private:
		const std::function<void(Context*)> function;

		/**
		 * For internal use.
		 */
		void handleContext(Context* context) override;

		JUCE_LEAK_DETECTOR(PluginHandler)
	};
}
