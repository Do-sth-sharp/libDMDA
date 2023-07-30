/*****************************************************************//**
 * \file    Context.cpp
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    July 2023
 * \version 1.0.0
 * \license	MIT License
 *********************************************************************/

#include "Context.h"

namespace DMDA {
	Context::~Context() {
		this->sendClosed();
	}

	void Context::addListener(Context::Listener* listener) {
		if (!listener) { return; }

		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.addIfNotAlreadyThere(listener);
	}

	void Context::removeListener(Context::Listener* listener) {
		if (!listener) { return; }

		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.removeAllInstancesOf(listener);
	}

	void Context::removeAllListeners() {
		juce::GenericScopedLock locker(this->listeners.getLock());
		this->listeners.clear();
	}

	void Context::sendClosed() const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->closed(const_cast<Context*>(this));
		}
	}

	void Context::sendDataChanged() const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->dataChanged(const_cast<Context*>(this));
		}
	}

	void Context::sendStateChanged(int32_t state) const {
		juce::GenericScopedLock locker(this->listeners.getLock());
		for (auto i : this->listeners) {
			i->stateChanged(const_cast<Context*>(this), state);
		}
	}

	void Context::handShake() {
		JUCE_ASSERT_MESSAGE_THREAD;
		this->handShaked = true;
		this->handShakedStateChanged();
	}

	void Context::handWave() {
		JUCE_ASSERT_MESSAGE_THREAD;
		this->handShaked = false;
		this->handShakedStateChanged();
	}

	bool Context::isHandShaked() const {
		return this->handShaked;
	}
}
