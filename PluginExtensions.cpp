#include "PluginExtensions.h"
#include "Macros.h"
#include "PluginProcessor.h"

namespace DMDA {
	Vst3Extensions::Vst3Extensions(PluginProcessor* processor)
		: processor(processor) {}

	int32_t Vst3Extensions::queryIAudioProcessor(
		const Steinberg::TUID id, void** obj) {
		if (memcmp(DMDA_HANDLE_ID_VST3, id, sizeof(Steinberg::TUID)) == 0) {
			if (!obj || !this->processor) {
				return static_cast<int32_t>(Vst3Result::ERROR);
			}
			(*obj) = reinterpret_cast<void*>(this->processor->getContext());
			return static_cast<int32_t>(Vst3Result::OK);
		}
		return static_cast<int32_t>(Vst3Result::ERROR);
	}
}
