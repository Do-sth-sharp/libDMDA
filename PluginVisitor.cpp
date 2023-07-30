/*****************************************************************//**
 * \file    PluginVisitor.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#include "PluginVisitor.h"
#include "Macros.h"
#include "Context.h"

#ifdef _MSC_VER
#pragma warning(disable : 5105)
#endif // MSC_VER

#include <pluginterfaces/vst/ivstcomponent.h>

#ifdef _MSC_VER
#pragma warning(default : 5105)
#endif // MSC_VER

namespace DMDA {
	void PluginVisitor::visitVST3Client(
		const juce::ExtensionsVisitor::VST3Client& client) {
		if (auto iComp = client.getIComponentPtr()) {
			void* ptrContext = nullptr;
			if (iComp->queryInterface(
				DMDA_HANDLE_ID_VST3, &ptrContext) == Steinberg::kResultOk) {
				if (ptrContext) {
					this->handleContext(reinterpret_cast<Context*>(ptrContext));
				}
			}
		}
	}

	PluginHandler::PluginHandler(std::function<void(Context*)> function)
		: PluginVisitor(), function(function) {}

	void PluginHandler::handleContext(Context* context) {
		if (this->function) {
			this->function(context);
		}
	}
}
