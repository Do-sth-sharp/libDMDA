#pragma once

#include <JuceHeader.h>

namespace DMDA {
	class Context;

	class PluginVisitor : public juce::ExtensionsVisitor {
	public:
		virtual ~PluginVisitor() override = default;
		void visitVST3Client(
			const juce::ExtensionsVisitor::VST3Client& client) override;

	protected:
		virtual void handleContext(Context*) = 0;

	private:
		JUCE_LEAK_DETECTOR(PluginVisitor)
	};

	class PluginHandler final : public PluginVisitor {
	public:
		PluginHandler() = delete;
		PluginHandler(std::function<void(Context*)> function);

	private:
		const std::function<void(Context*)> function;

		void handleContext(Context* context) override;

		JUCE_LEAK_DETECTOR(PluginHandler)
	};
}
