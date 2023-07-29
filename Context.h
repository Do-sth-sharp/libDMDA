#pragma once

#include <JuceHeader.h>

namespace DMDA {
	class Context {
	public:
		Context() = default;
		virtual ~Context();

	public:
		class Listener {
		public:
			virtual ~Listener() = default;

		protected:
			friend class Context;
			virtual void closed(Context*) {};
			virtual void dataChanged(Context*) {};
			virtual void stateChanged(Context*, int32_t) {};

		private:
			JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener)
		};

		void addListener(Listener* listener);
		void removeListener(Listener* listener);
		void removeAllListeners();

	public:
		void sendClosed() const;
		void sendDataChanged() const;
		void sendStateChanged(int32_t state) const;

	public:
		void handShake();
		void handWave();
		bool isHandShaked() const;

	private:
		juce::Array<Listener*, juce::CriticalSection> listeners;
		std::atomic_bool handShaked = false;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Context)
	};
}