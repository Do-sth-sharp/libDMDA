/*****************************************************************//**
 * \file    Context.h
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

namespace DMDA {
	/**
	 * The base class of all DMDA context types.
	 * 
	 * You can inherit this to create your own context types.
	 */
	class DMDA_API Context {
	public:
		Context() = default;
		virtual ~Context();

	public:
		/**
		 * The base class of context listeners.
		 * 
		 * You can inhert this in DMDA host then pass the object pointer
		 * to Context::addListener() method to listen the change of the context.
		 */
		class DMDA_API Listener {
		public:
			virtual ~Listener() = default;

		protected:
			friend class Context;
			/**
			 * This will be invoked when the DMDA plugin closed.
			 */
			virtual void closed(Context*) {};
			/**
			 * This will be invoked when the Context::sendDataChanged() has been called.
			 */
			virtual void dataChanged(Context*) {};
			/**
			 * This will be invoked with the state code 
			 * when the Context::sendStateChanged() has been called.
			 */
			virtual void stateChanged(Context*, int32_t) {};

		private:
			JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener)
		};

		/**
		 * Add a listener to the context in DMDA host.
		 * 
		 * You should ensure the listener object won't be deleted 
		 * before the plugin instance closed.
		 * Or you can call removeListener() method before delete the listener object.
		 */
		void addListener(Listener* listener);
		/**
		 * Remove a listener from the context in DMDA host.
		 */
		void removeListener(Listener* listener);
		/**
		 * Remove all listeners added to the context in DMDA host.
		 */
		void removeAllListeners();

	public:
		/**
		 * For internal use.
		 */
		void sendClosed() const;
		/**
		 * Send data changed signal to DMDA host in the plugin.
		 * 
		 * This will invoke the Listener::dataChanged() method.
		 */
		void sendDataChanged() const;
		/**
		 * Send state changed signal to DMDA host in the plugin.
		 * 
		 * This will invoke the Listener::stateChanged() method.
		 */
		void sendStateChanged(int32_t state) const;

	public:
		/**
		 * Call this in the DMDA host to hand shake with the plugin.
		 */
		void handShake();
		/**
		 * Call this in the DMDA host to hand wave with the plugin..
		 */
		void handWave();
		/**
		 * Check the hand shake state.
		 */
		bool isHandShaked() const;

	protected:
		/**
		 * This will be invoked when the hand shake state has been changed.
		 */
		virtual void handShakedStateChanged() {};

	private:
		juce::Array<Listener*, juce::CriticalSection> listeners;
		std::atomic_bool handShaked = false;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Context)
	};
}